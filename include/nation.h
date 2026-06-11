#include <string>

class Nation {
private:
    std::string m_name;
    std::string m_leader;
    int m_population;
    int m_stateMoney;
    float m_happiness;
    float m_politicalDirection;
    bool m_isWartime;

public:
    Nation(std::string name);
};