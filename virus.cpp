#include <windows.h>
#include <iostream>
using namespace std;

// Function to show a Windows notification
void ShowNotification(const string& message) {
    // Create a handle to a message-only window
    HWND hwnd = CreateWindowEx(
        0,                            // Optional window styles.
        "STATIC",                     // Window class
        "Notification",               // Window text
        0,                            // Window style
        0, 0, 0, 0,                   // Size and position
        HWND_MESSAGE,                 // Parent window
        NULL,                         // Menu
        GetModuleHandle(NULL),        // Instance handle
        NULL                          // Additional application data
    );

    if (hwnd == NULL) {
        cerr<< "Failed to create window." <<endl;
        return;
    }

    // Create a NOTIFYICONDATA structure
    NOTIFYICONDATA nid = {};
    nid.cbSize = sizeof(NOTIFYICONDATA);
    nid.hWnd = hwnd;
    nid.uID = 1001;
    nid.uFlags = NIF_INFO;
    strcpy_s(nid.szInfo, message.c_str());
    strcpy_s(nid.szInfoTitle, "You Are Hacked");
    nid.dwInfoFlags = NIIF_INFO;

    // Add the icon to the system tray
    Shell_NotifyIcon(NIM_ADD, &nid);

    // Display the notification
    Shell_NotifyIcon(NIM_MODIFY, &nid);

    // Sleep for a short duration to allow the notification to be displayed
    Sleep(1000);

    // Remove the icon from the system tray
    Shell_NotifyIcon(NIM_DELETE, &nid);

    // Destroy the window
    DestroyWindow(hwnd);
}

int main() {
    while (true) {
        ShowNotification("YOU ARE HACKED.");
       // Wait for 5 seconds before showing the next notification
    }
    return 0;
}
