
#include "ui/console/CConsole.h"
#include "ui/IUI.h"
#include "player/players/CHuman.h"
#include "player/players/CRandom.h"
#include "player/IPlayer.h"
#include "game/CController.h"
#include "util/CException.h"

#include <boost/program_options.hpp>
#include <stdlib.h>
#include <iostream>
#include <memory>

namespace po = boost::program_options;

static void displayExamples(const std::string & cmd) {
    std::cout << "Examples:" << std::endl;
    std::cout << "    to play against the computer" << std::endl;
    std::cout << "    " << cmd << std::endl;
    std::cout << std::endl;
    std::cout << "    to play against another person" << std::endl;
    std::cout << "    " << cmd << " --human" << std::endl;
    std::cout << std::endl;
    std::cout << "    to let the computer play against itself" << std::endl;
    std::cout << "    " << cmd << " --automatic" << std::endl;
    std::cout << std::endl;
    std::cout << "    to display this message" << std::endl;
    std::cout << "    " << cmd << " --help" << std::endl;
    std::cout << std::endl;
}

static po::variables_map parseOptions(int argc, const char * argv[]) {
    try {
        po::options_description desc("Allowed options");
        desc.add_options()
        ("help", "displays help message")
        ("human", "make human game (both players are humans)")
        ("automatic", "make automatic game (both players are robots)")
        ;

        po::variables_map vm;
        po::store(po::parse_command_line(argc, argv, desc), vm);
        po::notify(vm);

        if (vm.count("help")) {
            std::cout << desc << std::endl;
            displayExamples(argv[0]);
            exit(0);
        }

        return vm;
    } catch (boost::program_options::unknown_option & e) {
        std::cout << "Error: " << e.what() << std::endl;
        std::cout << "For proper usage:" << std::endl;
        std::cout << "    " << argv[0] << " --help" << std::endl;
        exit(1);
    }
}

int main(int argc, const char * argv []) {
    try {
        const auto vm = parseOptions(argc, argv);

        std::unique_ptr<ui::IUI> console(new ui::console::CConsole());
        std::unique_ptr<player::IPlayer> player1(new player::CHuman());
        std::unique_ptr<player::IPlayer> player2(new player::CRandom());
        if (vm.count("automatic")) {
            player1.reset(new player::CRandom());
        } else if (vm.count("human")) {
            player2.reset(new player::CHuman());
        }
        game::CController controller{std::move(console), std::move(player1), std::move(player2)};
        controller.run();
        return 0;
    } catch (const util::CException & e) {
        std::cout << "An ERROR occurred" << std::endl;
        std::cout << e.what() << std::endl;
        return 1;
    }
}

