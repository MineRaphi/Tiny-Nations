#include <string>

class Nation {
private:
   

public:
    std::string m_name;
    std::string m_leader;
    int m_population;
    int m_stateMoney;
    float m_happiness;
    float m_politicalDirection;
    bool m_isWartime;

    Nation(std::string name);
};