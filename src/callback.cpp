#include <iostream>
#include <memory>
#include <functional>
#include <string>

using MsgOnSuccess  = std::function<void(void)>;
using MsgOnError    = std::function<void(const std::string& msg)>;

class Messenger
{
private:
    MsgOnSuccess    m_on_success;
    MsgOnError      m_on_error;

public:
    void    setHandler(MsgOnSuccess on_success, MsgOnError on_error) {
        m_on_success = on_success;
        m_on_error = on_error;
    };
    void    sendMessage(const std::string& message) {
        if( message.size() == 0 ) {
            if( m_on_error )
                m_on_error("error message");
        }
    };
public:
    Messenger() = default;
    ~Messenger() = default;
};

int main(int argc, char** argv)
{
    auto messg = std::make_unique<Messenger>();

    messg->setHandler(
        []() { 
            std::cout << "Call on Succcess!\n"; 
        },
        [](const std::string& msg) { 
            std::cout << "Call on Error! " << msg << '\n';
        }
    );

    messg->sendMessage("Send msg");
    messg->sendMessage("");



    return 0;
};