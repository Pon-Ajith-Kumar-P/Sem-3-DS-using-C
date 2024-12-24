#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Song {
    int id;
    char name[100];
    char artist[100];
    struct Song *prev, *next;
} Song;

Song *head = NULL;

Song* createSong(int id, char *name, char *artist) {
    Song *new = (Song*)malloc(sizeof(Song));
    new->id = id;
    strcpy(new->name, name);
    strcpy(new->artist, artist);
    new->prev = new->next = new;
    return new;
}

void displaylist() {
    if (head == NULL) {
        printf("Playlist is empty!\n");
        return;
    }
    Song *temp = head;
    do {
        printf("ID: %d, Name: %s, Artist: %s\n", temp->id, temp->name, temp->artist);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

void addSong(int id, char *name, char *artist, int pos) {
    Song *new = createSong(id, name, artist);
    if (head == NULL) {
        head = new;
    } else 
    {
        Song *temp = head;
        if (pos == 1) {
            // Insert at the beginning
            Song *last = head->prev;
            new->next = head;
            new->prev = last;
            head->prev = new;
            last->next = new;
            head = new;
        } else {
            // Insert at a specific position or end
            int count = 1;
            while (temp->next != head && count < pos - 1) {
                temp = temp->next;
                count++;
            }
            new->next = temp->next;
            new->prev = temp;
            temp->next->prev = new;
            temp->next = new;
        }
    }
    displaylist();
}

void deleteSong(int id) {
    if (head == NULL) {
        printf("Playlist is empty!\n");
        return;
    }
    Song *temp = head;
    do {
        if (temp->id == id) 
        {
            if (temp == head && temp->next == head) 
            {
                // Only one song
                free(head);
                head = NULL;
            } 
            else 
            {
                Song *prev = temp->prev;
                Song *next = temp->next;
                prev->next = next;
                next->prev = prev;
                if (temp == head) {
                    head = next;
                }
                free(temp);
            }
            printf("Song with ID %d deleted!\n", id);
            displaylist();
            return;
        }
        temp = temp->next;
    } while (temp != head);
    printf("Song with ID %d not found!\n", id);
}

void updateSong(int id, char *name, char *artist) {
    if (head == NULL) {
        printf("Playlist is empty!\n");
        return;
    }
    Song *temp = head;
    do {
        if (temp->id == id) {
            strcpy(temp->name, name);
            strcpy(temp->artist, artist);
            printf("Song with ID %d updated!\n", id);
            displaylist();
            return;
        }
        temp = temp->next;
    } while (temp != head);
    printf("Song with ID %d not found!\n", id);
}

void retrieveSongs(char *songName) {
    if (head == NULL) {
        printf("Playlist is empty!\n");
        return;
    }
    Song *temp = head;
    char artist[100];
    int found = 0;

    do {
        if (strcmp(temp->name, songName) == 0) {
            strcpy(artist, temp->artist);
            printf("Artist: %s\n", artist);
            found = 1;
            break;
        }
        temp = temp->next;
    } while (temp != head);

    if (found) {
        printf("Other songs by %s:\n", artist);
        temp = head;
        do {
            if (strcmp(temp->artist, artist) == 0 && strcmp(temp->name, songName) != 0) {
                printf("%s\n", temp->name);
            }
            temp = temp->next;
        } while (temp != head);
    } else {
        printf("Song %s not found!\n", songName);
    }
}

void exitPlaylist() {
    if (head == NULL) return;
    Song *temp = head;
    do {
        Song *next = temp->next;
        free(temp);
        temp = next;
    } while (temp != head);
    head = NULL;
    printf("Playlist deallocated!\n");
}

int main() {
    int choice, id, position;
    char name[100], artist[100];

    while (1) {
        printf("\nMenu:\n");
        printf("1. Add Song\n");
        printf("2. Delete Song\n");
        printf("3. Update Song\n");
        printf("4. Retrieve Artist Songs\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Song ID, Name, Artist, and Position: ");
                scanf("%d%s%s%d", &id, name, artist, &position);
                addSong(id, name, artist, position);
                break;
            case 2:
                printf("Enter Song ID to delete: ");
                scanf("%d", &id);
                deleteSong(id);
                break;
            case 3:
                printf("Enter Song ID, New Name, and New Artist: ");
                scanf("%d%s%s", &id, name, artist);
                updateSong(id, name, artist);
                break;
            case 4:
                printf("Enter Song Name to retrieve artist: ");
                scanf("%s", name);
                retrieveSongs(name);
                break;
            case 5:
                exitPlaylist();
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
