#ifndef view_h
#define view_h

#define NBLIGNE 12
#define NBCOLONE 12

//Fichier header pour les fonctions de déplacement
void initialiser();
void afficherDamier();
Joueur* choixJoueur();

TypeCase verifierCase(int x, int y);
Case* recupererCellule(Coordonnees coordonnees);
Joueur* recupererJoueur(Couleur couleur);

Coordonnees preparerDeplacement(Coordonnees depart, Type typePion, Direction direction);
void deplacerPion(Coordonnees depart, Coordonnees arrive, Direction direction);
Coordonnees sauterPion(Case *cellule, Direction direction);

void jouerCoup();
void run();

#endif /* view_h */
