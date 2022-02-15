#ifndef __MODEL_DOCUMENTLOADER_HPP__
#define __MODEL_DOCUMENTLOADER_HPP__
#include <curl/curl.h>
#include <gumbo.h>
#include <string>
#include <map>

class Document;
class BrowserConfig;


class DocumentLoader {

    public:
        DocumentLoader(BrowserConfig *config);
        ~DocumentLoader();
        void load_async(Document *doc);
        void cancel_async_loading(Document *doc);
        bool is_loading(const Document *doc) const;

    private:
        BrowserConfig *config; // not owned
        
        struct curl_easy_request {
            CURL *handle = NULL;
            std::string buffer = "";
        };

        CURLM *curl;
        CURLSH *share;
        pthread_t thread_id;
        //char curl_errbuf[CURL_ERROR_SIZE];
        std::map<Document*, curl_easy_request> requests;

        // Executed in the main thread
        void add_request(Document *doc);
        void remove_request(Document *doc);
        void add_easy_handle(Document *doc);
        // Executed in a separate thread
        static uint append_to_buffer(char *chunck, uint size, uint nmemb, std::string *buffer);
        static void* load_documents(void *args);
};


#endif
