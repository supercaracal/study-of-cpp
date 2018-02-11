#include <iostream>
#include <fstream>
#include "headers/game.h"

/**
 * Move baggages to each goals.
 * You can specify a stage data file.
 * Specify with stdin or file path.
 *
 * Usage:
 *   $ make bin/01_03_05
 *   $ cat data/stage.txt | bin/01_03_05
 *   $ bin/01_03_05 < data/stage.txt
 *   $ bin/01_03_05 data/stage.txt
 *
 *   ########
 *   # .. p #
 *   # oo   #
 *   #      #
 *   ########
 */

static const int MAX_HEIGHT = 32;
static const int MAX_WIDTH = 32;

static void die(std::string msg);

int main(int argc, char *argv[]) {
  game g = game(MAX_HEIGHT, MAX_WIDTH);

  if (argc == 1) {
    g.load_stage(std::cin);
  } else {
    std::ifstream ifs(argv[1], std::ifstream::in);
    g.load_stage(ifs);
  }

  if (g.load_failed()) die("Could not load stage.");

  g.print_stage();
  exit(EXIT_SUCCESS);
}

static void die(std::string msg) {
  std::cout << msg << std::endl;
  exit(EXIT_FAILURE);
}
