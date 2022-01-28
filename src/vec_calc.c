#include "string.h" // strcmp()

#include "libs/util/_util.h"
#include "libs/vector/_vector.h"

void selection_handler(int sel)
{
  if (sel == 1)
  {
    int vec[] = {0, 0, 0};

    printf("\nVector (separated by ','): ");
    scanf("%d,%d,%d", &vec[0], &vec[1], &vec[2]);

    double l = vec_length(vec);
    printf("Length of the vector: %f\n\n", l);
  }
  else if (sel == 2)
  {
    int vec[] = {0, 0, 0};
    int vec1[] = {0, 0, 0};
    int rvec[] = {0, 0, 0};

    printf("\nVector 1 (separated by ','): ");
    scanf("%d,%d,%d", &vec[0], &vec[1], &vec[2]);
    printf("Vector 2 (separated by ','): ");
    scanf("%d,%d,%d", &vec1[0], &vec1[1], &vec1[2]);

    vec_add(vec, vec1, rvec);

    printf("Resulting Vector: {%d,%d,%d}\n\n", rvec[0], rvec[1], rvec[2]);
  }
  else if (sel == 3)
  {
    int vec[] = {0, 0, 0};
    int vec1[] = {0, 0, 0};
    int rvec[] = {0, 0, 0};

    printf("\nVector 1 (separated by ','): ");
    scanf("%d,%d,%d", &vec[0], &vec[1], &vec[2]);
    printf("Vector 2 (separated by ','): ");
    scanf("%d,%d,%d", &vec1[0], &vec1[1], &vec1[2]);

    vec_sub(vec, vec1, rvec);

    printf("Resulting Vector: {%d,%d,%d}\n\n", rvec[0], rvec[1], rvec[2]);
  }
  else if (sel == 8)
  {
    exit(0);
  }

  // creates endless loop
  helper_init_main();
  int _sel = get_selection();

  selection_handler(_sel);
}

int main(int argc, char *argv[])
{
  init_main(argc, argv);
  int sel = get_selection();

  selection_handler(sel);
  return 0;
}
