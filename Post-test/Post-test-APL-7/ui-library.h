#ifndef UI_LIBRARY_H
#define UI_LIBRARY_H

#include <iostream>
#include <string>
#include <thread>
#include <chrono>

using namespace std;

const string RESET = "\033[0m";
const string RED = "\033[31m";
const string GREEN = "\033[32m";
const string YELLOW = "\033[33m";
const string BLUE = "\033[34m";
const string CYAN = "\033[36m";
const string BOLD = "\033[1m";

void clear_screen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void cetak_garis() { 
    cout << CYAN << "\n===================================" << RESET; 
}

void cetak_garis(string teks) { 
    cout << CYAN << "\n=== " << YELLOW << BOLD << teks << RESET << CYAN << " ===" << RESET; 
}

void loading_animation(string message) {
    cout << CYAN << message;
    for(int i = 0; i < 3; i++) {
        cout << ".";
        this_thread::sleep_for(chrono::milliseconds(300)); // Delay 300ms
    }
    cout << RESET << "\n";
}

void print_error(string message) {
    cout << RED << BOLD << "[Error] " << message << RESET << "\n";
}

void print_success(string message) {
    cout << GREEN << BOLD << "[Sukses] " << message << RESET << "\n";
}

#endif