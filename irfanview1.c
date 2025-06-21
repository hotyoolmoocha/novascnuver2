#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct image {
    char header1[100];
    char header2[100];
    int width;
    int height; 
    int maxVal;
    unsigned char **img;
};

typedef struct image IMAGE;


void imageBrightness(IMAGE *image_in, IMAGE *image_out, int num);
void freeImage(IMAGE *image);

int main() {
    char fname[50], n_fname[50];
    char fpath[100] = "\"C:\\Program Files\\IrfanView\\i_view64.exe\" ";
    char n1_fpath[100];
    FILE *fp_in, *fp_out;
    IMAGE image_in, image_out;
    int i, j, brightness_adjust;

 
    printf("원본 파일의 이름 : ");
    scanf("%s", fname);


    fp_in = fopen(fname, "r");
    if (fp_in == NULL) {
        printf("파일을 열 수 없습니다.\n");
        return 1;
    }

    
    fgets(image_in.header1, sizeof(image_in.header1), fp_in);
    fgets(image_in.header2, sizeof(image_in.header2), fp_in);
    fscanf(fp_in, "%d %d", &image_in.width, &image_in.height);
    fscanf(fp_in, "%d", &image_in.maxVal);

   
    image_in.img = (unsigned char **)malloc(image_in.height * sizeof(unsigned char *));
    for (i = 0; i < image_in.height; i++) {
        image_in.img[i] = (unsigned char *)malloc(image_in.width * sizeof(unsigned char));
    }

   
    for (i = 0; i < image_in.height; i++) {
        for (j = 0; j < image_in.width; j++) {
            fscanf(fp_in, "%hhu", &image_in.img[i][j]);
        }
    }
    fclose(fp_in);


    printf("밝기 조절 값 (음수 가능): ");
    scanf("%d", &brightness_adjust);

    
    image_out = image_in; 
    imageBrightness(&image_in, &image_out, brightness_adjust);


    printf("저장할 파일의 이름 : ");
    scanf("%s", n_fname);

   
    fp_out = fopen(n_fname, "w");
    if (fp_out == NULL) {
        printf("파일을 열 수 없습니다.\n");
        freeImage(&image_in);
        return 1;
    }


    fputs(image_out.header1, fp_out);
    fputs(image_out.header2, fp_out);
    fprintf(fp_out, "%d %d\n", image_out.width, image_out.height);
    fprintf(fp_out, "%d\n", image_out.maxVal);


    for (i = 0; i < image_out.height; i++) {
        for (j = 0; j < image_out.width; j++) {
            fprintf(fp_out, "%hhu\n", image_out.img[i][j]);
        }
    }
    fclose(fp_out);

    strcpy(n1_fpath, fpath);
    strcat(n1_fpath, n_fname);
    system(n1_fpath);

 
    freeImage(&image_in);
    freeImage(&image_out);

    return 0;
}


void imageBrightness(IMAGE *image_in, IMAGE *image_out, int num) {
    int i, j;
    for (i = 0; i < image_in->height; i++) {
        for (j = 0; j < image_in->width; j++) {
            int new_value = image_in->img[i][j] + num;
            if (new_value < 0) {
                image_out->img[i][j] = 0;
            } else if (new_value > 255) {
                image_out->img[i][j] = 255;
            } else {
                image_out->img[i][j] = new_value;
            }
        }
    }
}


void freeImage(IMAGE *image) {
    for (int i = 0; i < image->height; i++) {
        free(image->img[i]);
    }
    free(image->img);
}
