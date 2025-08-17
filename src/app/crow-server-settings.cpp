#include "crow-server-settings.hpp"

#include <filesystem>
#include <fstream>
#include <sstream>
#include <string>

#include <crow.h>
#include <spdlog/spdlog.h>

namespace fs = std::filesystem;

std::string readFile(const std::string &path) {
  std::ifstream file(path);
  std::ostringstream ss;
  ss << file.rdbuf();
  return ss.str();
}

std::string load_file(const std::string& path) {
    std::ifstream in(path, std::ios::in | std::ios::binary);
    if (!in) return "";
    std::ostringstream contents;
    contents << in.rdbuf();
    return contents.str();
}

void StartCrowServerApp00() {
  // start the CROW server
  crow::SimpleApp app;

  // CROW_ROUTE(app, "/")([]() { return "Hello world"; });

  // Serve static files from "./ui"
  CROW_ROUTE(app, "/")([] {
    crow::response res;
    res.code = 200;
    res.set_header("Content-Type", "text/html");
    res.body = readFile("ui/app00/index.html");
    return res;
  });

  CROW_ROUTE(app, "/app.js")([] {
    crow::response res;
    res.code = 200;
    res.set_header("Content-Type", "application/javascript");
    res.body = readFile("ui/app00/app.js");
    return res;
  });

  app.port(18080).multithreaded().run();
  spdlog::info("CROW server started on port 18080");
}

void StartCrowServerApp01() {
  crow::SimpleApp app;

  // Serve index.html on root
  CROW_ROUTE(app, "/")
  ([]() {
    std::string content = load_file("dist/current/index.html");
    if (content.empty())
      return crow::response(404);
    crow::response res(content);
    res.set_header("Content-Type", "text/html");
    return res;
  });

  // // Serve static files (JS, CSS, images)
  // CROW_ROUTE(app, "/index.js")
  // ([](const std::string &path) {
  //   std::string fullPath = "dist/current" + path;
  //   if (!fs::exists(fullPath))
  //     return crow::response(404);

  //   std::string content = load_file(fullPath);
  //   crow::response res(content);

  //   // Basic MIME detection
  //   if (path.ends_with(".js"))
  //     res.set_header("Content-Type", "application/javascript");
  //   else if (path.ends_with(".css"))
  //     res.set_header("Content-Type", "text/css");
  //   else if (path.ends_with(".html"))
  //     res.set_header("Content-Type", "text/html");
  //   else if (path.ends_with(".png"))
  //     res.set_header("Content-Type", "image/png");
  //   else if (path.ends_with(".jpg") || path.ends_with(".jpeg"))
  //     res.set_header("Content-Type", "image/jpeg");

  //   return res;
  // });

  // // Example API endpoint for copy action
  // CROW_ROUTE(app, "/copy").methods("POST"_method)([](const crow::request &req) {
  //   auto json = crow::json::load(req.body);
  //   if (!json)
  //     return crow::response(400);

  //   std::string src = json["source"].s();
  //   std::string dst = json["destination"].s();

  //   try {
  //     fs::create_directories(dst);
  //     for (auto &p : fs::directory_iterator(src)) {
  //       fs::copy(p.path(), dst,
  //                fs::copy_options::overwrite_existing |
  //                    fs::copy_options::recursive);
  //     }
  //     return crow::response(200, "Copy complete");
  //   } catch (std::exception &e) {
  //     return crow::response(500, e.what());
  //   }
  // });

  // app.port(8080).multithreaded().run();
}