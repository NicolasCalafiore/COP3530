//#include "../main.cpp"
//#define CATCH_CONFIG_MAIN
//#include "catch.hpp"
//#include <string>
//#include "../Graph.h"
//#include "../Input.h"
//
//using namespace std;
//TEST_CASE("Input Size 1 Accuracy Test", "[flag]"){
//
//    vector<string> connections;
//    int p = 2;
//    connections.push_back("pcbuildinguf.com apple.com");
//    Graph graph = Input::ReadData(connections);
//    graph.InitializePageRanks();
//    graph.PageRank(p);
//    vector<string> response = graph.ReturnPageRanks();
//
//    vector<string> solution = {"apple.com 0.50", "pcbuildinguf.com 0.00"};
//
//
//	REQUIRE(response == solution);
//}
//TEST_CASE("Power Iteration 1 Accuracy Test", "[flag]"){
//
//    vector<string> connections;
//    int p = 1;
//
//    connections.push_back("facebook.com pcbuildinguf.com");
//    connections.push_back("microsoft.com facebook.com");
//    connections.push_back("facebook.com python.org");
//    connections.push_back("reactjs.org pcbuildinguf.com");
//    connections.push_back("reactjs.org python.org");
//    connections.push_back("python.org reactjs.org");
//    connections.push_back("facebook.com microsoft.com");
//
//    Graph graph = Input::ReadData(connections);
//    graph.InitializePageRanks();
//    graph.PageRank(p);
//    vector<string> response = graph.ReturnPageRanks();
//
//    vector<string> solution = {
//            "facebook.com 0.20",
//            "microsoft.com 0.20",
//            "pcbuildinguf.com 0.20",
//            "python.org 0.20",
//            "reactjs.org 0.20"
//    };
//
//
//    REQUIRE(response == solution);
//}
//TEST_CASE("Large Sample Stability Test", "[flag]"){
//
//    vector<string> connections;
//    int p = 2;
//
//    for(int i = 0; i < 10000; i++) {
//        int to = rand() % 10000 + 1;
//        connections.push_back(to_string(i) + " " + to_string(to));
//    }
//
//    Graph graph = Input::ReadData(connections);
//    graph.InitializePageRanks();
//    graph.PageRank(p);
//    vector<string> response = graph.ReturnPageRanks();
//
//
//    REQUIRE(response.size() == response.size());
//}
//TEST_CASE("High Power Iteration Accuracy Test", "[flag]"){
//
//    vector<string> connections;
//    int p = 10000;
//
//    connections.push_back("microsoft.com apple.com");
//    connections.push_back("mozilla.org roblox.com");
//    connections.push_back("disney.com python.org");
//    connections.push_back("instagram.com reactjs.org");
//    connections.push_back("instagram.com microsoft.com");
//    connections.push_back("microsoft.com facebook.com");
//    connections.push_back("apple.com disney.com");
//    connections.push_back("ufl.edu facebook.com");
//
//    Graph graph = Input::ReadData(connections);
//    graph.InitializePageRanks();
//    graph.PageRank(p);
//    vector<string> response = graph.ReturnPageRanks();
//
//    vector<string> solution = {
//            "apple.com 0.00",
//            "disney.com 0.00",
//            "facebook.com 0.00",
//            "instagram.com 0.00",
//            "microsoft.com 0.00",
//            "mozilla.org 0.00",
//            "python.org 0.00",
//            "reactjs.org 0.00",
//            "roblox.com 0.00",
//            "ufl.edu 0.00",
//    };
//
//
//    REQUIRE(response == solution);
//}
//TEST_CASE("Large Sample Accuracy Test", "[flag]"){
//
//    vector<string> connections;
//    int p = 17;
//
//    connections.push_back("chase.com zoom.us");
//    connections.push_back("wikipedia.org ufl.edu");
//    connections.push_back("openai.com stackoverflow.com");
//    connections.push_back("aman.com python.org");
//    connections.push_back("weather.com ufl.edu");
//    connections.push_back("aman.com wikipedia.org");
//    connections.push_back("facebook.com google.com");
//    connections.push_back("weather.com github.com");
//    connections.push_back("youtube.com python.org");
//    connections.push_back("google.com getbootstrap.com");
//    connections.push_back("python.org zoom.us");
//    connections.push_back("disney.com facebook.com");
//    connections.push_back("aman.com github.com");
//    connections.push_back("wikipedia.org stackoverflow.com");
//    connections.push_back("google.com roblox.com");
//    connections.push_back("github.com chase.com");
//    connections.push_back("samsung.com github.com");
//    connections.push_back("youtube.com chase.com");
//    connections.push_back("stackoverflow.com instagram.com");
//    connections.push_back("pcbuildinguf.com weather.com");
//    connections.push_back("github.com samsung.com");
//    connections.push_back("disney.com samsung.com");
//    connections.push_back("google.com chase.com");
//    connections.push_back("stackoverflow.com pcbuildinguf.com");
//    connections.push_back("disney.com openai.com");
//    connections.push_back("facebook.com stackoverflow.com");
//    connections.push_back("roblox.com stackoverflow.com");
//    connections.push_back("disney.com chase.com");
//    connections.push_back("microsoft.com twitter.com");
//    connections.push_back("twitter.com stackoverflow.com");
//    connections.push_back("disney.com twitter.com");
//    connections.push_back("google.com facebook.com");
//    connections.push_back("aman.com pcbuildinguf.com");
//    connections.push_back("python.org stackoverflow.com");
//    connections.push_back("zoom.us github.com");
//    connections.push_back("roblox.com mozilla.org");
//    connections.push_back("stackoverflow.com openai.com");
//    connections.push_back("pcbuildinguf.com chase.com");
//    connections.push_back("microsoft.com weather.com");
//    connections.push_back("zoom.us apple.com");
//    connections.push_back("samsung.com instagram.com");
//    connections.push_back("chase.com pcbuildinguf.com");
//    connections.push_back("google.com twitter.com");
//    connections.push_back("facebook.com github.com");
//    connections.push_back("wikipedia.org apple.com");
//    connections.push_back("youtube.com facebook.com");
//    connections.push_back("ufl.edu youtube.com");
//    connections.push_back("getbootstrap.com samsung.com");
//    connections.push_back("getbootstrap.com apple.com");
//    connections.push_back("python.org apple.com");
//    connections.push_back("github.com ufl.edu");
//    connections.push_back("disney.com apple.com");
//    connections.push_back("facebook.com mozilla.org");
//    connections.push_back("microsoft.com stackoverflow.com");
//    connections.push_back("apple.com facebook.com");
//    connections.push_back("aman.com mozilla.org");
//    connections.push_back("samsung.com disney.com");
//    connections.push_back("stackoverflow.com youtube.com");
//    connections.push_back("wikipedia.org pcbuildinguf.com");
//    connections.push_back("openai.com github.com");
//    connections.push_back("openai.com youtube.com");
//    connections.push_back("ufl.edu zoom.us");
//    connections.push_back("disney.com google.com");
//    connections.push_back("pcbuildinguf.com roblox.com");
//    connections.push_back("openai.com mozilla.org");
//    connections.push_back("stackoverflow.com zoom.us");
//    connections.push_back("mozilla.org stackoverflow.com");
//    connections.push_back("getbootstrap.com instagram.com");
//    connections.push_back("github.com mozilla.org");
//    connections.push_back("facebook.com disney.com");
//    connections.push_back("openai.com zoom.us");
//    connections.push_back("openai.com aman.com");
//    connections.push_back("chase.com apple.com");
//    connections.push_back("pcbuildinguf.com python.org");
//    connections.push_back("microsoft.com instagram.com");
//    connections.push_back("github.com youtube.com");
//    connections.push_back("wikipedia.org chase.com");
//    connections.push_back("openai.com instagram.com");
//    connections.push_back("github.com weather.com");
//    connections.push_back("google.com openai.com");
//    connections.push_back("weather.com roblox.com");
//    connections.push_back("apple.com github.com");
//    connections.push_back("apple.com getbootstrap.com");
//    connections.push_back("weather.com openai.com");
//    connections.push_back("mozilla.org github.com");
//    connections.push_back("roblox.com instagram.com");
//    connections.push_back("mozilla.org twitter.com");
//    connections.push_back("chase.com aman.com");
//    connections.push_back("ufl.edu github.com");
//    connections.push_back("mozilla.org aman.com");
//    connections.push_back("mozilla.org youtube.com");
//    connections.push_back("python.org disney.com");
//    connections.push_back("weather.com getbootstrap.com");
//    connections.push_back("apple.com twitter.com");
//    connections.push_back("disney.com github.com");
//    connections.push_back("aman.com openai.com");
//    connections.push_back("openai.com twitter.com");
//    connections.push_back("mozilla.org getbootstrap.com");
//    connections.push_back("mozilla.org apple.com");
//    connections.push_back("aman.com microsoft.com");
//    connections.push_back("youtube.com ufl.edu");
//    connections.push_back("instagram.com ufl.edu");
//    connections.push_back("aman.com twitter.com");
//    connections.push_back("openai.com chase.com");
//    connections.push_back("roblox.com twitter.com");
//    connections.push_back("python.org weather.com");
//    connections.push_back("getbootstrap.com github.com");
//    connections.push_back("ufl.edu wikipedia.org");
//    connections.push_back("pcbuildinguf.com stackoverflow.com");
//    connections.push_back("disney.com stackoverflow.com");
//    connections.push_back("aman.com facebook.com");
//    connections.push_back("pcbuildinguf.com aman.com");
//    connections.push_back("python.org pcbuildinguf.com");
//    connections.push_back("openai.com getbootstrap.com");
//    connections.push_back("apple.com roblox.com");
//    connections.push_back("github.com apple.com");
//    connections.push_back("apple.com mozilla.org");
//    connections.push_back("weather.com mozilla.org");
//    connections.push_back("youtube.com aman.com");
//    connections.push_back("disney.com getbootstrap.com");
//    connections.push_back("stackoverflow.com samsung.com");
//    connections.push_back("weather.com python.org");
//    connections.push_back("mozilla.org openai.com");
//    connections.push_back("zoom.us ufl.edu");
//    connections.push_back("mozilla.org weather.com");
//    connections.push_back("getbootstrap.com pcbuildinguf.com");
//    connections.push_back("chase.com wikipedia.org");
//    connections.push_back("microsoft.com apple.com");
//    connections.push_back("wikipedia.org python.org");
//    connections.push_back("microsoft.com disney.com");
//    connections.push_back("facebook.com apple.com");
//    connections.push_back("zoom.us pcbuildinguf.com");
//    connections.push_back("openai.com microsoft.com");
//    connections.push_back("wikipedia.org twitter.com");
//    connections.push_back("microsoft.com ufl.edu");
//    connections.push_back("microsoft.com aman.com");
//    connections.push_back("samsung.com mozilla.org");
//    connections.push_back("zoom.us samsung.com");
//    connections.push_back("instagram.com zoom.us");
//    connections.push_back("openai.com apple.com");
//    connections.push_back("chase.com getbootstrap.com");
//    connections.push_back("samsung.com twitter.com");
//    connections.push_back("weather.com disney.com");
//    connections.push_back("twitter.com roblox.com");
//    connections.push_back("disney.com mozilla.org");
//    connections.push_back("ufl.edu openai.com");
//    connections.push_back("ufl.edu disney.com");
//    connections.push_back("youtube.com weather.com");
//    connections.push_back("facebook.com chase.com");
//    connections.push_back("twitter.com getbootstrap.com");
//    connections.push_back("getbootstrap.com openai.com");
//    connections.push_back("samsung.com pcbuildinguf.com");
//    connections.push_back("facebook.com aman.com");
//    connections.push_back("aman.com apple.com");
//    connections.push_back("pcbuildinguf.com microsoft.com");
//    connections.push_back("aman.com weather.com");
//    connections.push_back("disney.com instagram.com");
//    connections.push_back("disney.com python.org");
//    connections.push_back("pcbuildinguf.com samsung.com");
//    connections.push_back("wikipedia.org disney.com");
//    connections.push_back("wikipedia.org zoom.us");
//    connections.push_back("pcbuildinguf.com mozilla.org");
//    connections.push_back("samsung.com weather.com");
//    connections.push_back("github.com facebook.com");
//    connections.push_back("facebook.com ufl.edu");
//    connections.push_back("samsung.com microsoft.com");
//    connections.push_back("google.com zoom.us");
//    connections.push_back("chase.com python.org");
//    connections.push_back("zoom.us microsoft.com");
//    connections.push_back("chase.com samsung.com");
//    connections.push_back("openai.com wikipedia.org");
//    connections.push_back("aman.com zoom.us");
//    connections.push_back("aman.com instagram.com");
//    connections.push_back("wikipedia.org mozilla.org");
//    connections.push_back("openai.com python.org");
//    connections.push_back("google.com pcbuildinguf.com");
//    connections.push_back("chase.com instagram.com");
//    connections.push_back("facebook.com python.org");
//    connections.push_back("getbootstrap.com wikipedia.org");
//    connections.push_back("samsung.com google.com");
//    connections.push_back("weather.com stackoverflow.com");
//    connections.push_back("disney.com microsoft.com");
//    connections.push_back("getbootstrap.com weather.com");
//    connections.push_back("youtube.com getbootstrap.com");
//    connections.push_back("instagram.com getbootstrap.com");
//    connections.push_back("google.com samsung.com");
//    connections.push_back("twitter.com chase.com");
//    connections.push_back("getbootstrap.com youtube.com");
//    connections.push_back("roblox.com google.com");
//    connections.push_back("twitter.com disney.com");
//    connections.push_back("stackoverflow.com twitter.com");
//    connections.push_back("mozilla.org samsung.com");
//    connections.push_back("chase.com roblox.com");
//    connections.push_back("ufl.edu aman.com");
//    connections.push_back("roblox.com samsung.com");
//    connections.push_back("facebook.com wikipedia.org");
//    connections.push_back("weather.com aman.com");
//    connections.push_back("chase.com mozilla.org");
//    connections.push_back("facebook.com getbootstrap.com");
//    connections.push_back("samsung.com getbootstrap.com");
//
//
//    Graph graph = Input::ReadData(connections);
//    graph.InitializePageRanks();
//    graph.PageRank(p);
//    vector<string> response = graph.ReturnPageRanks();
//
//    vector<string> solution = {
//            "aman.com 0.04",
//            "apple.com 0.06",
//            "chase.com 0.04",
//            "disney.com 0.04",
//            "facebook.com 0.03",
//            "getbootstrap.com 0.07",
//            "github.com 0.06",
//            "google.com 0.02",
//            "instagram.com 0.04",
//            "microsoft.com 0.03",
//            "mozilla.org 0.06",
//            "openai.com 0.04",
//            "pcbuildinguf.com 0.05",
//            "python.org 0.03",
//            "roblox.com 0.03",
//            "samsung.com 0.06",
//            "stackoverflow.com 0.05",
//            "twitter.com 0.05",
//            "ufl.edu 0.05",
//            "weather.com 0.05",
//            "wikipedia.org 0.03",
//            "youtube.com 0.04",
//            "zoom.us 0.05",
//    };
//
//
//    REQUIRE(response == solution);
//}