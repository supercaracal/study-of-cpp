#include <iostream>

/**
 * Move baggages to each goals.
 *
 * ########
 * # .. p #
 * # oo   #
 * #      #
 * ########
 */

static const char USAGE[] = "w:up z:down a:left s:right q:end";
static const char END_MESSAGE[] = "Thank you.";

static const char MARK_PLAYER = 'p';
static const char MARK_BUGGAGE = 'o';
static const char MARK_GOAL = '.';
static const char MARK_WALL = '#';
static const char MARK_BLANK = ' ';

#define MAX_Y 5
#define MAX_X 9

struct pos {
  int y;
  int x;
};

struct game {
  pos player;
  pos baggage1;
  pos baggage2;
  pos goal1;
  pos goal2;
};

static void initialize(game *g);
static bool valid(game *g, char field[MAX_Y][MAX_X], int x, int y);
static bool on_goal(pos target, game *g);
static void move(game *g, char field[MAX_Y][MAX_X]);
static char read_key(void);
static void clear(char field[MAX_Y][MAX_X]);
static void draw(char field[MAX_Y][MAX_X]);

int main(int argc, char *argv[]) {
  char field[MAX_Y][MAX_X] = {
    { "########" },
    { "#      #" },
    { "#      #" },
    { "#      #" },
    { "########" }
  };

  static game g;
  initialize(&g);
  move(&g, field);
  draw(field);
  std::cerr << USAGE << std::endl;

  char key;
  while ((key = read_key())) {
    switch (key) {
      case 'w':
        if (valid(&g, field, g.player.y - 1, g.player.x)) g.player.y -= 1;
        break;
      case 'z':
        if (valid(&g, field, g.player.y + 1, g.player.x)) g.player.y += 1;
        break;
      case 'a':
        if (valid(&g, field, g.player.y, g.player.x - 1)) g.player.x -= 1;
        break;
      case 's':
        if (valid(&g, field, g.player.y, g.player.x + 1)) g.player.x += 1;
        break;
      case 'q':
        std::cerr << END_MESSAGE << std::endl;
        exit(0);
      default:
        std::cerr << USAGE << std::endl;
        exit(1);
    }
    move(&g, field);
    draw(field);
    std::cerr << USAGE << std::endl;
  }
  exit(0);
}

static void initialize(game *g) {
  g->player = { 1, 5 };
  g->baggage1 = { 2, 2 };
  g->baggage2 = { 2, 3 };
  g->goal1 = { 1, 2 };
  g->goal2 = { 1, 3 };
}

static char read_key(void) {
  char c;
  std::cin >> c;
  return c;
}

static bool valid(game *g, char field[MAX_Y][MAX_X], int y, int x) {
  bool on_baggage1 = g->baggage1.y == y && g->baggage1.x == x;
  bool on_baggage2 = g->baggage2.y == y && g->baggage2.x == x;
  bool on_wall = field[y][x] == MARK_WALL;
  return !on_baggage1 && !on_baggage2 && !on_wall;
}

static void move(game *g, char field[MAX_Y][MAX_X]) {
  // TODO: Move baggages.
  clear(field);
  field[g->goal1.y][g->goal1.x] = MARK_GOAL;
  field[g->goal2.y][g->goal2.x] = MARK_GOAL;
  field[g->player.y][g->player.x] = on_goal(g->player, g) ? 'P' : MARK_PLAYER;
  field[g->baggage1.y][g->baggage1.x] = on_goal(g->baggage1, g) ? 'O' : MARK_BUGGAGE;
  field[g->baggage2.y][g->baggage2.x] = on_goal(g->baggage2, g) ? 'O' : MARK_BUGGAGE;
}

static bool on_goal(pos target, game *g) {
  return (target.y == g->goal1.y && target.x == g->goal1.x)
    || (target.y == g->goal2.y && target.x == g->goal2.x);
}

static void clear(char field[MAX_Y][MAX_X]) {
  int i;
  int j;
  int x_last = MAX_X - 1;
  for (i = 0; i < MAX_Y; ++i) {
    for (j = 0; j < x_last; ++j) {
      if (field[i][j] == MARK_WALL) {
        continue;
      }
      field[i][j] = MARK_BLANK;
    }
  }
}

static void draw(char field[MAX_Y][MAX_X]) {
  int i;
  for (i = 0; i < MAX_Y; ++i) {
    std::cout << field[i] << std::endl;
  }
}
