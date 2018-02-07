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
static const char MESSAGE_QUIT[] = "Bye bye.";
static const char MESSAGE_GOAL[] = "Finish!!";

static const char MARK_PLAYER = 'p';
static const char MARK_PLAYER_ON_GOAL = 'P';
static const char MARK_BAGGAGE = 'o';
static const char MARK_BAGGAGE_ON_GOAL = 'O';
static const char MARK_GOAL = '.';
static const char MARK_WALL = '#';
static const char MARK_BLANK = ' ';

#define MAX_Y 5
#define MAX_X 8
#define BAGGAGE_COUNT 2

struct pos {
  int y;
  int x;
};

struct game {
  pos player;
  pos baggages[BAGGAGE_COUNT];
  pos goals[BAGGAGE_COUNT];
};

static void initialize(game *g);
static char read_key(void);
static void move_player(game *g, char key);
static bool move_baggage(game *g, pos delta, pos player);
static bool on_wall(int y, int x);
static bool on_goal(game *g, int y, int x);
static bool on_baggage(game *g, int y, int x);
static bool is_goal(game *g);
static void draw(game *g);

int main(int argc, char *argv[]) {
  static game g;
  initialize(&g);
  draw(&g);

  char key;
  while ((key = read_key())) {
    if (key == 'q') {
      break;
    }
    move_player(&g, key);
    draw(&g);
    if (is_goal(&g)) {
      std::cerr << MESSAGE_GOAL << std::endl;
      break;
    }
  }

  std::cerr << MESSAGE_QUIT << std::endl;
  exit(0);
}

static void initialize(game *g) {
  g->player = { 1, 5 };
  g->baggages[0] = { 2, 2 };
  g->baggages[1] = { 2, 3 };
  g->goals[0] = { 1, 2 };
  g->goals[1] = { 1, 3 };
}

static char read_key(void) {
  char c;
  std::cin >> c;
  return c;
}

static void move_player(game *g, char key) {
  pos delta = { 0, 0 };

  switch (key) {
    case 'w':
      --delta.y;
      break;
    case 'z':
      ++delta.y;
      break;
    case 'a':
      --delta.x;
      break;
    case 's':
      ++delta.x;
      break;
  }

  pos p = { g->player.y + delta.y, g->player.x + delta.x };

  if (on_wall(p.y, p.x)) {
    return;
  }

  if (on_baggage(g, p.y, p.x)) {
    bool moved = move_baggage(g, delta, p);
    if (!moved) return;
  }

  g->player.y += delta.y;
  g->player.x += delta.x;
}

static bool move_baggage(game *g, pos delta, pos player) {
  pos before;
  pos after;
  int i;
  for (i = 0; i < BAGGAGE_COUNT; ++i) {
    before = { g->baggages[i].y, g->baggages[i].x };
    if (before.y != player.y || before.x != player.x) {
      continue;
    }
    if (on_goal(g, before.y, before.x)) {
      continue;
    }
    after = { g->baggages[i].y + delta.y, g->baggages[i].x + delta.x };
    if (on_wall(after.y, after.x) || on_baggage(g, after.y, after.x)) {
      continue;
    }
    g->baggages[i].y += delta.y;
    g->baggages[i].x += delta.x;
    return true;
  }
  return false;
}

static bool on_wall(int y, int x) {
  int last_y = MAX_Y - 1;
  int last_x = MAX_X - 1;
  return y == 0 || y == last_y || x == 0 || x == last_x;
}

static bool on_goal(game *g, int y, int x) {
  int i;
  for (i = 0; i < BAGGAGE_COUNT; ++i) {
    pos goal = g->goals[i];
    if (goal.y == y && goal.x == x) {
      return true;
    }
  }
  return false;
}

static bool on_baggage(game *g, int y, int x) {
  int i;
  for (i = 0; i < BAGGAGE_COUNT; ++i) {
    pos baggage = g->baggages[i];
    if (baggage.y == y && baggage.x == x) {
      return true;
    }
  }
  return false;
}

static bool is_goal(game *g) {
  int i;
  int j;
  int by;
  int bx;
  int gy;
  int gx;
  bool match = false;
  for (i = 0; i < BAGGAGE_COUNT; ++i) {
    by = g->baggages[i].y;
    bx = g->baggages[i].x;
    match = false;
    for (j = 0; j < BAGGAGE_COUNT; ++j) {
      gy = g->goals[j].y;
      gx = g->goals[j].x;
      if (by == gy && bx == gx) {
        match = true;
        continue;
      }
    }
    if (!match) return match;
  }
  return match;
}

static void draw(game *g) {
  int i;
  int j;
  char c;
  for (i = 0; i < MAX_Y; ++i) {
    for (j = 0; j < MAX_X; ++j) {
      if (on_wall(i, j)) {
        c = MARK_WALL;
      } else if (i == g->player.y && j == g->player.x) {
        c = on_goal(g, i, j) ? MARK_PLAYER_ON_GOAL : MARK_PLAYER;
      } else if (on_baggage(g, i, j)) {
        c = on_goal(g, i, j) ? MARK_BAGGAGE_ON_GOAL : MARK_BAGGAGE;
      } else if (on_goal(g, i, j)) {
        c = MARK_GOAL;
      } else {
        c = MARK_BLANK;
      }
      std::cout << c;
    }
    std::cout << std::endl;
  }
  std::cerr << USAGE << std::endl;
}
