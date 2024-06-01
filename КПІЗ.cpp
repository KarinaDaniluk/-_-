#include <iostream>
#include <vector>
#include <iomanip>  // для std::setfill та std::setw

class Clock {
public:
    enum DisplayStyle { HOUR_24, HOUR_12 };

    Clock(DisplayStyle style, int hours, int minutes, int seconds)
        : style(style), hours(hours), minutes(minutes), seconds(seconds) {}

    void setTime(int hours, int minutes, int seconds) {
        this->hours = hours;
        this->minutes = minutes;
        this->seconds = seconds;
    }

    void displayTime() const {
        if (style == HOUR_24) {
            std::cout << std::setfill('0') << std::setw(2) << hours << ":"
                      << std::setfill('0') << std::setw(2) << minutes << ":"
                      << std::setfill('0') << std::setw(2) << seconds;
        } else {
            int displayHours = hours % 12;
            if (displayHours == 0) displayHours = 12;
            std::cout << std::setfill('0') << std::setw(2) << displayHours << ":"
                      << std::setfill('0') << std::setw(2) << minutes << ":"
                      << std::setfill('0') << std::setw(2) << seconds << " "
                      << (hours >= 12 ? "PM" : "AM");
        }
        std::cout << std::endl;
    }

private:
    DisplayStyle style;
    int hours;
    int minutes;
    int seconds;
};

int main() {
    std::vector<Clock> clocks;

    // Додавання об'єктів годинника до контейнера
    clocks.emplace_back(Clock::HOUR_24, 14, 30, 45);
    clocks.emplace_back(Clock::HOUR_12, 2, 30, 45);
    clocks.emplace_back(Clock::HOUR_24, 23, 59, 59);
    clocks.emplace_back(Clock::HOUR_12, 11, 59, 59);

    // Виведення часу для кожного годинника
    for (const auto& clock : clocks) {
        clock.displayTime();
    }

    // Зміна часу для одного з годинників
    clocks[0].setTime(9, 15, 0);

    // Виведення часу після зміни
    std::cout << "Після зміни часу:\n";
    for (const auto& clock : clocks) {
        clock.displayTime();
    }

    return 0;
}
