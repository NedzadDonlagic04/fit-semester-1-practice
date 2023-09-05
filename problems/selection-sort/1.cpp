#include<iostream>
#include"./headers/generateData.hpp"

namespace ctm = custom;

void selectionSort(std::vector<ctm::Post> &posts, bool sortDescending=0) {
    for(std::size_t i = 0; i < posts.size(); i++) {
        for(std::size_t ii = i + 1; ii < posts.size(); ii++) {
            if(sortDescending && posts[i].getLikes() < posts[ii].getLikes()) std::swap(posts[i], posts[ii]);        
            else if(posts[i].getLikes() > posts[ii].getLikes()) std::swap(posts[i], posts[ii]);        
        }
    }
}

void outputPostData(const std::vector<ctm::Post> &posts, const std::string &text) {
    std::cout<<text<<'\n';

    for(const auto &post : posts) {
        std::cout<<post.formattedPostInfo()<<'\n';
    }
    std::cout<<'\n';
}

int main(int argv, char* argc[]) {
    auto posts { ctm::getRandomPostData(100) }; 

    outputPostData(posts, "Posts before ASCENDED sort: ");

    selectionSort(posts);
    outputPostData(posts, "Posts after ASCENDED sort: ");

    selectionSort(posts, true);
    outputPostData(posts, "Posts after DESCENDED sort: ");

    return 0;
}
