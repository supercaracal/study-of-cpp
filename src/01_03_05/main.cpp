#include <iostream>
#include <fstream>

/**
 * Move baggages to each goals.
 * You can specify a stage data.
 * Specify with stdin or file path.
 *
 * ########
 * # .. p #
 * # oo   #
 * #      #
 * ########
 */

static const int MAX_HEIGHT = 32;
static const int MAX_WIDTH = 32;
using stage_lines_t = std::string[MAX_HEIGHT];

static void load_stage(std::istream& is, stage_lines_t& sl);
static void print_stage(stage_lines_t& sl);
static void die(std::string msg);

int main(int argc, char *argv[]) {
  stage_lines_t sl;

  if (argc == 1) {
    load_stage(std::cin, sl);
  } else {
    std::ifstream ifs(argv[1], std::ifstream::in);
    load_stage(ifs, sl);
  }

  print_stage(sl);
  exit(EXIT_SUCCESS);
}

static void load_stage(std::istream& is, stage_lines_t& sl) {
  if (is.fail()) die("Could not load stage.");

  char buf[MAX_WIDTH];
  for (int i = 0; is.good(); i++) {
    is.getline(buf, MAX_WIDTH);
    sl[i] = buf;
  }
}

static void print_stage(stage_lines_t& sl) {
  for (int i = 0; !sl[i].empty(); ++i) {
    std::cout << sl[i] << std::endl;
  }
}

static void die(std::string msg) {
  std::cout << msg << std::endl;
  exit(EXIT_FAILURE);
}
