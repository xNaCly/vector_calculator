#include "libs/util/_util.h"
#include "libs/vector/_vector.h"

void selection_handler(int sel) {
  if (sel == 1) {
    int vec[] = {0, 0, 0};

    printf("\nVector (separated by ','): ");
    scanf("%d,%d,%d", &vec[0], &vec[1], &vec[2]);

    double l = vec_length(vec);
    printf("Length of the vector: %s%s%f%s\n\n", ANSI_COLOR_GREEN_BG, ANSI_COLOR_BLACK, l,
           ANSI_RESET);
  } else if (sel == 2) {
    int vec[] = {0, 0, 0};
    int vec1[] = {0, 0, 0};
    int rvec[] = {0, 0, 0};

    printf("\nVector 1 (separated by ','): ");
    scanf("%d,%d,%d", &vec[0], &vec[1], &vec[2]);
    printf("Vector 2 (separated by ','): ");
    scanf("%d,%d,%d", &vec1[0], &vec1[1], &vec1[2]);

    vec_add(vec, vec1, rvec);

    printf("Resulting Vector: %s%s{%d,%d,%d}%s\n\n", ANSI_COLOR_GREEN_BG, ANSI_COLOR_BLACK, rvec[0],
           rvec[1], rvec[2], ANSI_RESET);
  } else if (sel == 3) {
    int vec[] = {0, 0, 0};
    int vec1[] = {0, 0, 0};
    int rvec[] = {0, 0, 0};

    printf("\nVector 1 (separated by ','): ");
    scanf("%d,%d,%d", &vec[0], &vec[1], &vec[2]);
    printf("Vector 2 (separated by ','): ");
    scanf("%d,%d,%d", &vec1[0], &vec1[1], &vec1[2]);

    vec_sub(vec, vec1, rvec);

    printf("Resulting Vector: %s%s{%d,%d,%d}%s\n\n", ANSI_COLOR_GREEN_BG, ANSI_COLOR_BLACK, rvec[0],
           rvec[1], rvec[2], ANSI_RESET);
  } else if (sel == 4) {
    int vec[] = {0, 0, 0};
    int fac = 0;
    int rvec[] = {0, 0, 0};

    printf("\nVector (separated by ','): ");
    scanf("%d,%d,%d", &vec[0], &vec[1], &vec[2]);

    printf("Factor: ");
    scanf("%d", &fac);

    vec_fac(vec, fac, rvec);

    printf("Resulting Vector: %s%s{%d,%d,%d}%s\n\n", ANSI_COLOR_GREEN_BG, ANSI_COLOR_BLACK, rvec[0],
           rvec[1], rvec[2], ANSI_RESET);
  } else if (sel == 5) {
    int vec[] = {0, 0, 0};
    int vec1[] = {0, 0, 0};

    printf("\nVector 1 (separated by ','): ");
    scanf("%d,%d,%d", &vec[0], &vec[1], &vec[2]);
    printf("Vector 2 (separated by ','): ");
    scanf("%d,%d,%d", &vec1[0], &vec1[1], &vec1[2]);

    int r = scalar_prod(vec, vec1);

    printf("Scalar of the two vectors: %s%s%d%s\n\n", ANSI_COLOR_GREEN_BG, ANSI_COLOR_BLACK, r,
           ANSI_RESET);
  } else if (sel == 6) {
    int vec[] = {0, 0, 0};
    int vec1[] = {0, 0, 0};

    printf("\nVector 1 (separated by ','): ");
    scanf("%d,%d,%d", &vec[0], &vec[1], &vec[2]);
    printf("Vector 2 (separated by ','): ");
    scanf("%d,%d,%d", &vec1[0], &vec1[1], &vec1[2]);

    double a = angle_between(vec, vec1);

    printf("Angle between the two vectors: %s%s%f%s\n\n", ANSI_COLOR_GREEN_BG, ANSI_COLOR_BLACK, a,
           ANSI_RESET);

  } else if (sel == 7) {
    int vec[] = {0, 0, 0};
    int vec1[] = {0, 0, 0};
    int rvec[] = {0, 0, 0};

    printf("\nVector 1 (separated by ','): ");
    scanf("%d,%d,%d", &vec[0], &vec[1], &vec[2]);
    printf("Vector 2 (separated by ','): ");
    scanf("%d,%d,%d", &vec1[0], &vec1[1], &vec1[2]);

    vec_prod(vec, vec1, rvec);

    printf("Resulting Vector: %s%s{%d,%d,%d}%s\n\n", ANSI_COLOR_GREEN_BG, ANSI_COLOR_BLACK, rvec[0],
           rvec[1], rvec[2], ANSI_RESET);
  } else if (sel == 8) {
    int vec[] = {0, 0, 0};
    int vec1[] = {0, 0, 0};
    int vec2[] = {0, 0, 0};

    printf("\nVector 1 (separated by ','): ");
    scanf("%d,%d,%d", &vec[0], &vec[1], &vec[2]);
    printf("Vector 2 (separated by ','): ");
    scanf("%d,%d,%d", &vec1[0], &vec1[1], &vec1[2]);
    printf("Vector 3 (separated by ','): ");
    scanf("%d,%d,%d", &vec2[0], &vec2[1], &vec2[2]);

    int tp = triple_prod(vec, vec1, vec2);
    printf("Tripple product of the three vectors: %s%s%d%s\n\n",
           ANSI_COLOR_GREEN_BG, ANSI_COLOR_BLACK, tp, ANSI_RESET);
  } else if (sel == 9) {
    exit(0);
  }

  // creates endless selection loop for the user
  helper_init_main();
  int sel_ = get_selection();

  selection_handler(sel_);
}

int main(int argc, char *argv[]) {
  init_main(argc, argv);
  int sel = get_selection();

  selection_handler(sel);
  return 0;
}
