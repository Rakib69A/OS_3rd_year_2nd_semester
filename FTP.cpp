#include <iostream>
#include <curl/curl.h>

using namespace std;

int main() {
    // Initialize libcurl
    CURL *curl;
    CURLcode res = curl_global_init(CURL_GLOBAL_DEFAULT);

    if (res != CURLE_OK) {
        cerr << "Curl global initialization failed: " << curl_easy_strerror(res) << endl;
        return 1;
    }

    curl = curl_easy_init();

    if (!curl) {
        cerr << "Curl initialization failed" << endl;
        return 1;
    }

    // Set FTP URL
    const char *ftp_url = "ftp://ftp.example.com/remote-file.txt"; // Replace with your FTP server and file

    // Set FTP username and password
    curl_easy_setopt(curl, CURLOPT_USERNAME, "your_username");
    curl_easy_setopt(curl, CURLOPT_PASSWORD, "your_password");

    // Set the FTP URL to download from
    curl_easy_setopt(curl, CURLOPT_URL, ftp_url);

    // Perform the FTP transfer
    res = curl_easy_perform(curl);

    if (res != CURLE_OK) {
        cerr << "FTP transfer failed: " << curl_easy_strerror(res) << endl;
    } else {
        cout << "FTP transfer successful" << endl;
    }

    // Clean up
    curl_easy_cleanup(curl);
    curl_global_cleanup();

    return 0;
}

