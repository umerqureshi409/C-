#include <windows.h>
#include <string>
#include <sstream>

#define ID_CALCULATE_BUTTON 1

LRESULT CALLBACK WindowProcedure(HWND, UINT, WPARAM, LPARAM);

HWND hMarks[5], hTotal, hPercentage, hStatus, hButton;

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR args, int ncmdshow) {
    WNDCLASSW wc = {0};

    wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hInstance = hInst;
    wc.lpszClassName = L"marksheetWindowClass";
    wc.lpfnWndProc = WindowProcedure;

    if (!RegisterClassW(&wc))
        return -1;

    CreateWindowW(L"marksheetWindowClass", L"Marksheet Calculator", WS_OVERLAPPEDWINDOW | WS_VISIBLE, 100, 100, 350, 300, NULL, NULL, NULL, NULL);

    MSG msg = {0};

    while (GetMessage(&msg, NULL, NULL, NULL)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}

void AddControls(HWND hwnd) {
    CreateWindowW(L"static", L"Enter Marks for 5 Subjects:", WS_VISIBLE | WS_CHILD, 50, 20, 200, 20, hwnd, NULL, NULL, NULL);

    for (int i = 0; i < 5; i++) {
        hMarks[i] = CreateWindowW(L"edit", L"", WS_VISIBLE | WS_CHILD | WS_BORDER, 50, 50 + (30 * i), 50, 20, hwnd, NULL, NULL, NULL);
    }

    hButton = CreateWindowW(L"button", L"Calculate", WS_VISIBLE | WS_CHILD, 50, 200, 100, 30, hwnd, (HMENU)ID_CALCULATE_BUTTON, NULL, NULL);
    
    hTotal = CreateWindowW(L"static", L"Total Marks: ", WS_VISIBLE | WS_CHILD, 50, 240, 200, 20, hwnd, NULL, NULL, NULL);
    hPercentage = CreateWindowW(L"static", L"Percentage: ", WS_VISIBLE | WS_CHILD, 50, 260, 200, 20, hwnd, NULL, NULL, NULL);
    hStatus = CreateWindowW(L"static", L"Status: ", WS_VISIBLE | WS_CHILD, 50, 280, 200, 20, hwnd, NULL, NULL, NULL);
}

void CalculateMarks(HWND hwnd) {
    int marks[5], total = 0;
    wchar_t buffer[256];
    
    for (int i = 0; i < 5; i++) {
        GetWindowTextW(hMarks[i], buffer, 256);
        marks[i] = _wtoi(buffer);
        total += marks[i];
    }

    double percentage = total / 5.0;

    std::wstringstream wsTotal, wsPercentage, wsStatus;
    wsTotal << L"Total Marks: " << total;
    wsPercentage << L"Percentage: " << percentage << L"%";
    wsStatus << L"Status: " << (percentage >= 50 ? L"Pass" : L"Fail");

    SetWindowTextW(hTotal, wsTotal.str().c_str());
    SetWindowTextW(hPercentage, wsPercentage.str().c_str());
    SetWindowTextW(hStatus, wsStatus.str().c_str());
}

LRESULT CALLBACK WindowProcedure(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp) {
    switch (msg) {
        case WM_COMMAND:
            if (LOWORD(wp) == ID_CALCULATE_BUTTON) {
                CalculateMarks(hwnd);
            }
            break;
        case WM_CREATE:
            AddControls(hwnd);
            break;
        case WM_DESTROY:
            PostQuitMessage(0);
            break;
        default:
            return DefWindowProcW(hwnd, msg, wp, lp);
    }
    return 0;
}
