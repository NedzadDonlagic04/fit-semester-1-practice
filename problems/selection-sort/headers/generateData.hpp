#include<string>
#include<vector>
#include<fstream>
#include<random>

namespace detail {
    [[nodiscard]] std::vector<std::string> getAllPostTitles() {
        std::ifstream file("./txt/postTitles.txt");
        std::string line {};
        std::vector<std::string> postTitles {};

        while(std::getline(file, line)) postTitles.push_back(line);

        return postTitles;
    }
}

namespace custom {
    class Post {
        private:
            int likes {};
            int dislikes {};
            std::string title {};
        
        public:
            Post() = default;
            Post(const Post&) = default;

            Post(int likes, int dislikes, const std::string &title) : likes(likes), dislikes(dislikes), title(title) {}

            [[nodiscard]] inline int getLikes() const {
                return this->likes;
            }

            [[nodiscard]] inline int getDislikes() const {
                return this->dislikes;
            }

            [[nodiscard]] inline std::string getTitle() const {
                return this->title;
            }

            [[nodiscard]] inline std::string formattedPostInfo() const {
                return "Post Title: \"" + this->title + "\"\nLikes: " + std::to_string(this->likes) + "\nDislikes: " + std::to_string(this->dislikes) + '\n';
            }

            void swap(Post &other) {
                std::swap(this->likes, other.likes);
                std::swap(this->dislikes, other.dislikes);
                this->title.swap(other.title);
            }

            Post& operator=(Post other) {
                this->swap(other);

                return *this;
            }

            ~Post() {}
    };
    
    /* 
        Constants that represent the minimum
        and maximum amount of likes / dislikes
        a post can have
    */
    constexpr int MIN_REACTIONS = 0;
    constexpr int MAX_REACTIONS = 200000;

    [[nodiscard]] std::vector<Post> getRandomPostData(int numbersToGenerate) {
        if (numbersToGenerate < 1) numbersToGenerate = 1;
        const auto postTitles { detail::getAllPostTitles() };
        std::vector<Post> randomPostData (numbersToGenerate); 

        std::random_device rd {};
        std::mt19937 rng(rd());
        std::uniform_int_distribution<> postLikesDistribution (MIN_REACTIONS, MAX_REACTIONS);
        std::uniform_int_distribution<> postDislikesDistribution (MIN_REACTIONS, MAX_REACTIONS);
        std::uniform_int_distribution<> postTitleDistribution (0, postTitles.size());

        for(std::size_t i = 0; i < randomPostData.size(); i++) {
            int likes { postLikesDistribution(rng) };
            int dislikes { postDislikesDistribution(rng) };
            std::size_t titleIndex = postTitleDistribution(rng);

            randomPostData[i] = Post(likes, dislikes, postTitles[titleIndex]);
        }

        return randomPostData;
    }
}