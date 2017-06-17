#include "ExternalPlayer.hpp"


/*
 * COMMUNICATION
 */

// Wrapping pipe in a class makes sure they are closed when we leave scope
class cpipe {
private:
    int fd[2];
public:
    const inline int read_fd() const { return fd[0]; }
    const inline int write_fd() const { return fd[1]; }
    cpipe() { if (pipe(fd)) throw std::runtime_error("Failed to create pipe"); }
    void close() { ::close(fd[0]); ::close(fd[1]); }
    ~cpipe() { close(); }
};


//
// Usage:
//   spawn s(argv)
//   s.stdin << ...
//   s.stdout >> ...
//   s.send_eol()
//   s.wait()
//
class spawn {
private:
    cpipe write_pipe;
    cpipe read_pipe;
public:
    int child_pid = -1;
    std::unique_ptr<__gnu_cxx::stdio_filebuf<char> > write_buf = NULL;
    std::unique_ptr<__gnu_cxx::stdio_filebuf<char> > read_buf = NULL;
    std::ostream stdin;
    std::istream stdout;

    spawn(const char* const argv[], bool with_path = false, const char* const envp[] = 0): stdin(NULL), stdout(NULL) {
        child_pid = fork();
        if (child_pid == -1) throw std::runtime_error("Failed to start child process");
        if (child_pid == 0) {   // In child process
            dup2(write_pipe.read_fd(), STDIN_FILENO);
            dup2(read_pipe.write_fd(), STDOUT_FILENO);
            write_pipe.close(); read_pipe.close();
            int result;
            if (with_path) {
                if (envp != 0) result = execvpe(argv[0], const_cast<char* const*>(argv), const_cast<char* const*>(envp));
                else result = execvp(argv[0], const_cast<char* const*>(argv));
            }
            else {
                if (envp != 0) result = execve(argv[0], const_cast<char* const*>(argv), const_cast<char* const*>(envp));
                else result = execv(argv[0], const_cast<char* const*>(argv));
            }
            if (result == -1) {
               // Note: no point writing to stdout here, it has been redirected
               std::cerr << "Error: Failed to launch program" << std::endl;
               exit(1);
            }
        }
        else {
            close(write_pipe.read_fd());
            close(read_pipe.write_fd());
            write_buf = std::unique_ptr<__gnu_cxx::stdio_filebuf<char> >(new __gnu_cxx::stdio_filebuf<char>(write_pipe.write_fd(), std::ios::out));
            read_buf = std::unique_ptr<__gnu_cxx::stdio_filebuf<char> >(new __gnu_cxx::stdio_filebuf<char>(read_pipe.read_fd(), std::ios::in));
            stdin.rdbuf(write_buf.get());
            stdout.rdbuf(read_buf.get());
        }
    }

    void send_eof() { write_buf->close(); }

    int wait() {
        int status;
        waitpid(child_pid, &status, 0);
        return status;
    }
};

/*
 * END COMMUNICATION
 */


ExternalPlayer::ExternalPlayer ()
{

}

ExternalPlayer::~ExternalPlayer ()
{
}


Joueur* ExternalPlayer::clone () const
{
    return new ExternalPlayer (*this);
}


void ExternalPlayer::startGame ()
{
    const char* const argv[] = {m_chemin.c_str(), (const char*)0};
    m_prog = new spawn(argv);
}

void ExternalPlayer::endGame ()
{
    m_prog->send_eof();
}


Action ExternalPlayer::jouerAction (const InformationsTourJoueur &informations)
{
    m_prog->stdin << informations.m_joueurs.size() << " " << informations.m_idJoueur << std::endl;

    for (unsigned int iJoueur=0; iJoueur<informations.m_joueurs.size(); iJoueur++) {
        m_prog->stdin << informations.m_joueurs[iJoueur].first.second << " " << informations.m_joueurs[iJoueur].first.first << " "
                      << informations.m_joueurs[iJoueur].second.second << " " << informations.m_joueurs[iJoueur].second.first << std::endl;
    }

    std::string sortie;
    std::getline(m_prog->stdout, sortie);


    Action action;
    action.setDirection(Action::HAUT);

    if (sortie == "LEFT") {
        action.setDirection(Action::GAUCHE);
    }
    else if (sortie == "RIGHT") {
        action.setDirection(Action::DROITE);
    }
    else if (sortie == "UP") {
        action.setDirection(Action::HAUT);
    }
    else if (sortie == "DOWN") {
        action.setDirection(Action::BAS);
    }

    return action;
}
