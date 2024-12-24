#include <Windows.h>
#include <iostream>
#include <vector>

#include <tabulate/table.hpp>
using namespace tabulate;

BOOL CALLBACK EnumWindowsProc(HWND hwnd, LPARAM lParam) {
    if (IsWindowVisible(hwnd)) {
        DWORD processId;
        GetWindowThreadProcessId(hwnd, &processId);

        char windowTitle[256];
        GetWindowText(hwnd, windowTitle, sizeof(windowTitle));
        if (strlen(windowTitle) > 0) {
            auto *windowInfo = reinterpret_cast<std::vector<std::pair<std::string, DWORD>> *>(lParam);
            windowInfo->emplace_back(windowTitle, processId);
        }
    }
    return TRUE;
}

int main() {
    std::vector<std::pair<std::string, DWORD>> allWindowInfo;
    EnumWindows(EnumWindowsProc, reinterpret_cast<LPARAM>(&allWindowInfo));
    Table universal_constants;
    for (const auto &info: allWindowInfo) {
        universal_constants.add_row({std::string(info.first),std::to_string(info.second)});
    }
//    universal_constants.format().font_background_color(Color::red).font_color(Color::white);
    universal_constants.print(std::cout);
    return 0;
}
