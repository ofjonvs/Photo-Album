#include <stdio.h>
#include <string.h>
#include "photo_album.h"
#include <stdlib.h>

/*Returns a dynamically-allocated Photo structure
  initialized based on the provided parameters*/
Photo *create_photo(int id, const char *description){
  Photo *photo = (Photo*)malloc(sizeof(Photo));
  /*sets photo description to null if description parameter is null and 
    returns null if photo is null*/
  if(description == NULL){
    photo->description = NULL;
    return photo;
  }
  if(photo == NULL){
    return NULL;
  }
   
  /*sets photo id equal to id parameter and dynamically allocates description
    parameter to photo descritpion*/
  photo->id = id;
  photo->description = (char*)malloc(strlen(description) + 1);
  if(photo->description == NULL){
    return NULL;
  }
  strcpy(photo->description, description);
  return photo;
}
/*prints output format if photo and description are not null*/
void print_photo(Photo *photo){
  if(photo == NULL){}
  else{
    if(photo->description == NULL){
      printf("None\n");
    }
    else{
      printf("Photo ID: %d, Description: %s\n", photo->id, 
	     photo->description);
    }
  }
}

/*frees dynamically allocated memory if photo is not null*/
void destroy_photo(Photo *photo){
  if(photo == NULL){}
  else{
    free(photo->description);
    free(photo);
  }
}

/*initializes album size to 0 if album is not null*/
void initialize_album(Album *album){
  if(album == NULL){}
  else{
    album->size = 0;
  }
}

/*prints contents of album if album is not null*/
void print_album(const Album *album){
  if(album == NULL){}
  else{
    if(album->size == 0){
      printf("Album has no photos.\n");
    }
    /*prints out contents of each photo*/
    else{
      int i = 0;
      for(i = 0; i < album->size; i ++){
	print_photo(album->all_photos[i]);
      }
    }
  }
}

/*frees dynamically allocated memory*/
void destroy_album(Album *album){
  if(album == NULL){}
  else{
    int i;
    /*frees memory from each photo in album*/
    for(i = 0; i < album->size; i++){
      destroy_photo(album->all_photos[i]);
    }
    album->size = 0;
  }
}

/*appends photo to end of album if album is not null and there is room*/
void add_photo_to_album(Album *album, int id, const char *description){
  if(album == NULL && album->size >= MAX_ALBUM_SIZE){}
  else{
    /*appends photo object to last entry and increments size*/
    Photo *photo  = create_photo(id, description);
    if(photo){
      album->all_photos[album->size++] = photo;
    }
  }
}
