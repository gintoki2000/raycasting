#include "ioutils.h"
#include "level-parser.h"
#include "lib/mlx.h"
#include "types.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

#define RET_VAL_IF_FAIL(con, val)                                              \
  if (!(con))                                                                  \
  return (val)

/*
#define ECS 53

static int on_key_pressed(context_t *ctx, int keycode) { return 0; }

static int on_loop(context_t *ctx) { return 0; }

static int is_number(char c) { return c > '0' && c < '9'; }

static int init(context_t *ctx, const level_data_t *level_data) {
  ctx->mlx_ptr = mlx_init();
  RET_VAL_IF_FAIL(ctx->mlx_ptr != NULL, -1);
  ctx->window_ptr =
      mlx_new_window(ctx->mlx_ptr, level_data->window_width,
                     level_data->window_height, level_data->window_title);
  RET_VAL_IF_FAIL(ctx->window_ptr != NULL, -1);

  mlx_key_hook(ctx->window_ptr, on_key_pressed, ctx);
  mlx_loop_hook(ctx->window_ptr, on_loop, ctx);

  return 0;
}

static void destroy(context_t *ctx) {
  mlx_destroy_window(ctx->mlx_ptr, ctx->window_ptr);
}*/

int main(int argc, char** argv)
{
  level_data_t* level_data;

  if ((level_data = load_level_data("./map.cub")) == NULL)
  {
    return -1;
  }

  free(level_data);
  return 0;
}
