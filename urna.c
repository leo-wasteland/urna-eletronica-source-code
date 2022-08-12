#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BRAZIL_POPULATION 10

void
getVotes(unsigned int **votes, size_t i) {
  if (i == BRAZIL_POPULATION - 2) return;
  unsigned int vote;

  printf("Numero do seu candidato: ");
  scanf("%d", &vote);

  unsigned int vote_position = rand() % BRAZIL_POPULATION; // Diego Aranha is screaming

  (*votes)[vote_position]  = vote;
  
  printf("Seu voto(%d): %d\n", vote_position, (*votes)[vote_position]);

  getVotes(&(*votes), ++i);
}

void
getWinner(unsigned int **votes, unsigned int *winner) {
  *winner = rand() % BRAZIL_POPULATION;
}

int
main(void)
{
  srand(time(NULL));
  
  unsigned int *votes = malloc(BRAZIL_POPULATION * sizeof(unsigned int)); 
  unsigned int winner;

  getVotes(&votes, 0);
  getWinner(&votes, &winner);

  printf("Eleito: %d!", *(votes + winner));  

  return 0;
}