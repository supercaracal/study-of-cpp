#include <iostream>
#include <fstream>
#include "game.h"

/**
 * Move baggages to each goals.
 * You can specify a stage data file.
 * Specify with stdin or file path.
 *
 * Usage:
 *   $ make bin/01_03_05
 *   $ bin/01_03_05 data/stage.txt
 *
 *   ########
 *   # .. p #
 *   # oo   #
 *   #      #
 *   ########
 */

static void die(std::string msg);

int main(int argc, char *argv[]) {
  game* g = new game();

  if (argc != 2) {
    delete g;
    die("Please specify a stage file.");
  } else {
    std::ifstream ifs(argv[1], std::ifstream::in);
    g->load_stage(ifs);
  }

  if (g->load_failed()) {
    delete g;
    die("Could not load stage.");
  }

  g->run();

  delete g;
  exit(EXIT_SUCCESS);
}

static void die(std::string msg) {
  std::cout << msg << std::endl;
  exit(EXIT_FAILURE);
}
