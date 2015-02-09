/*

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "SDL.h"

#define HAUT	0
#define DROITE	1
#define BAS	2
#define GAUCHE	3

#define AUCUNE_DIRECTION	0
#define DIRECTION_HAUT		1
#define DIRECTION_DROITE	2
#define DIRECTION_BAS		4
#define DIRECTION_GAUCHE	8

#define LARGEUR_ECRAN 640
#define HAUTEUR_ECRAN 480

typedef struct
{
	// pour l'affichage

	SDL_Surface *image;
	SDL_Rect source;
	SDL_Rect dest;


	// taille du sprite

	int largeur;
	int hauteur;

	// pour le déplacement

	// direction dans laquelle se deplace le sprite
	int direction;
	// vitesse du sprite
	int vitesse;
	// pour la gestion des animations

	// si le sprite est anime
	int anim;
	// direction dans laquelle est orienté le sprite
	int orientation;
	// animation courante du sprite
	int anim_courante;

	// le temps que dure une animation
	int temps_anim;

	// le temps de l'animation courante
	int temps_anim_courante;

	// nombre d'animations du sprite
	int total_anims;

}Sprite;

SDL_Surface *loadBmp(const char *fichier)
{
	SDL_Surface *image;

	/* Chargement du bitmap "fichier" en memoire dans la surface image */
	image = SDL_LoadBMP(fichier);
	if ( image == NULL )
	{
		fprintf(stderr, "Echec de chargement du fichier %s : %s.\n", fichier, SDL_GetError());
		return NULL;
	}

	/* Verification du format de l'image */
	if ( (image->w != 128) || (image->h != 128) )
	if ( image == NULL )
	{
		fprintf(stderr, "L'image du fichier %s doit être de taille 96*128 pixels.\n", fichier);
		SDL_FreeSurface(image);
		return NULL;
	}

	return image;
}

int chargerSprite( Sprite *sprite, const char *image )
{
	sprite->image = loadBmp( image );
	if ( !sprite->image )
		return 0;

	// on fixe la cle de transparance
	SDL_SetColorKey( sprite->image, SDL_SRCCOLORKEY, SDL_MapRGB( sprite->image->format, 255, 0, 0 ) );

	// On definit d'abord les propriétés du sprite :

	// le sprite n'est pas animé par defaut
	sprite->anim = 0;

	// on commence par la première animation
	sprite->anim_courante = 0;

	// le sprite dispose de trois animations
	sprite->total_anims = 4;

	// par défaut, le sprite est tourné vers le bas
	sprite->orientation = BAS;

	// chaque animation dure 5 affichages
	sprite->temps_anim = 8;

	// Le temps qu'il reste à afficher l'animation courante
	sprite->temps_anim_courante = 0;

	// On definit ensuite les dimentions du sprite.
	sprite->largeur = 32;
	sprite->hauteur = 32;

	sprite->source.x = sprite->anim_courante * sprite->largeur;
	sprite->source.y = sprite->orientation * sprite->hauteur;
	sprite->source.w = sprite->largeur;
	sprite->source.h = sprite->hauteur;

	sprite->dest.x = 0;
	sprite->dest.y = 0;
	sprite->dest.w = sprite->largeur;
	sprite->dest.h = sprite->hauteur;

	// on definit enfin la vitesse et la direction du sprite
	sprite->vitesse = 2;
	sprite->direction = AUCUNE_DIRECTION;

	return 1;
}

void supprimerSprite( Sprite *sprite )
{
	SDL_FreeSurface( sprite->image );
}

void fixerDirectionSprite( Sprite *sprite, int direction )
{
	// On affecte la direction au sprite
	sprite->direction = direction;

	// on affecte l'animation correcpondant à la direction au sprite
	if (direction != AUCUNE_DIRECTION)
	{
		sprite->anim = 1;
		switch (direction)
		{
		case DIRECTION_HAUT:
			sprite->orientation = HAUT;
			break;

		case DIRECTION_DROITE:
			sprite->orientation = DROITE;
			break;

		case DIRECTION_BAS:
			sprite->orientation = BAS;
			break;

		case DIRECTION_GAUCHE:
			sprite->orientation = GAUCHE;
			break;

		default:
			;
		}
	}
	else
		// si le sprite est areté, on ne l'anime pas
		sprite->anim = 0;

	// on met la première animation
	sprite->anim_courante = 0;
	sprite->temps_anim_courante = 0;

	// on regle la source de l'image à copier
	sprite->source.y = sprite->orientation * sprite->hauteur;
	sprite->source.x = sprite->anim_courante * sprite->largeur;
}

void miseAJourSprite( Sprite *sprite )
{
	// le sprite vas vers le haut
	if (sprite->direction & DIRECTION_HAUT)
	{
		// on monte et on faut attention a ne pas sortie de l'ecran
		sprite->dest.y -= sprite->vitesse;
		if (sprite->dest.y < 0)
			sprite->dest.y = 0;
	}
	else if (sprite->direction & DIRECTION_DROITE)
	{
		// on va à droite et on fait attention a ne pas sortie de l'ecran
		sprite->dest.x += sprite->vitesse;
		if (sprite->dest.x + sprite->largeur > LARGEUR_ECRAN)
			sprite->dest.x = LARGEUR_ECRAN - sprite->largeur;
	}
	else if (sprite->direction & DIRECTION_BAS)
	{
		// on descend et on faut attention a ne pas sortie de l'ecran
		sprite->dest.y += sprite->vitesse;
		if (sprite->dest.y + sprite->hauteur > HAUTEUR_ECRAN)
			sprite->dest.y = HAUTEUR_ECRAN - sprite->hauteur;
	}
	else if (sprite->direction & DIRECTION_GAUCHE)
	{
		// on va à gauche et on fait attention a ne pas sortie de l'ecran
		sprite->dest.x -= sprite->vitesse;
		if (sprite->dest.x < 0)
			sprite->dest.x = 0;
	}
}

void dessinerSprite( Sprite *sprite, SDL_Surface *destination )
{
	/* si le sprite est animé, on gere l'animation */
	if (sprite->anim)
	{
		// on decremente le temps restant à l'animation courante
		sprite->temps_anim_courante--;
		// et on regarde s'il est temps de changer d'animation
		if ( sprite->temps_anim_courante <= 0 )
		{
			// s'il faut changer, on passe à l'animation suivante
			sprite->anim_courante++;
			// si on était à la dernière animation, on repasse à la première
			if (sprite->anim_courante >= sprite->total_anims)
				sprite->anim_courante = 0;

			// on regle la source à copier
			sprite->source.x = sprite->largeur * sprite->anim_courante;
			sprite->temps_anim_courante = sprite->temps_anim;
		}
	}

	// enfin, on dessine le sprite à l'ecran
	SDL_BlitSurface( sprite->image, &sprite->source, destination, &sprite->dest );
}
/*
int main(int ac, char **av)
{

	SDL_Surface *ecran;
	SDL_Event event;
	int bFin = 0;
	Uint32 temps_courant, prochain_rendu = 0;

    freopen("CON", "w", stdout);
    freopen("CON", "r", stdin);
    freopen("CON", "w", stderr);
    ac = ac+1;
    (void)av;
	/* On déclare trois sprites, un que l'on controlera
	   et deux qui se déplacerons tout seul */
	Sprite spControlable;//spAutonome1, spAutonome2;

	/* on declare des variables qui signalerons quand
	   il sera temps aux sprites autonomes de changer de direction */
//	int changement_direction1, changement_direction2;

	/* initialisation de SDL_Video */
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) < 0)
	{
		fprintf(stderr, "Echec d'initialisation de SDL.\n");
		return 1;
	}
	printf("Bonjour le monde, SDL est initialisé avec succès.\n");


	/* On fixe le mode d'affichage à 640*480*16 plein ecran.*/
	ecran = SDL_SetVideoMode(640, 480, 16, SDL_HWSURFACE);
	if ( ecran == NULL )
	{
		fprintf(stderr, "Echec de changement du mode video : %s.\n", SDL_GetError());
		return 1;
	}

	/* On charge le sprite controlable avec l'image pecheur.bmp */
	if ( !chargerSprite( &spControlable, "pecheur.bmp" ) )
	{
		SDL_Quit();
		return 1;
	}

	/* On charge le premier sprite autonome avec l'image bebe.bmp */
	//if ( !chargerSprite( &spAutonome1, "bebe.bmp" ) )
//	{
//		supprimerSprite( &spControlable );
//		SDL_Quit();
//		return 1;
//	}

	/* On charge le second sprite autonome avec l'image souris.bmp */
//	if ( !chargerSprite( &spAutonome2, "souris.bmp" ) )
//	{
//		supprimerSprite( &spAutonome1 );
//		supprimerSprite( &spControlable );
//		SDL_Quit();
//		return 1;
//	}

	// on place les sprites à l'écran
//	spAutonome1.dest.x = 160;
//	spAutonome1.dest.y = 160;

//spAutonome2.dest.x = 480;
	//spAutonome2.dest.y = 320;

	//srand( (unsigned)time(NULL) );
	// on lance un deplacement aléatoire pour les sprites autonomes
	// on genere un nombre entre 1, 2, 4 et 8 pour chaque sprite
//	fixerDirectionSprite( &spAutonome1 , 1 << (rand()%4) );
//	fixerDirectionSprite( &spAutonome2 , 1 << (rand()%4) );

	// on fixe dans combien de temps les sprites changerons de direction
	//changement_direction1 = rand()%100 + 50;
//	changement_direction2 = rand()%100 + 50;

	// on place le sprite que l'on controle au milieu
	spControlable.dest.x = 304;
	spControlable.dest.y = 260;
	fixerDirectionSprite( &spControlable, DIRECTION_BAS );
	fixerDirectionSprite( &spControlable, AUCUNE_DIRECTION );

	while (!bFin)
	{
		while (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
			case SDL_KEYDOWN:
				switch (event.key.keysym.sym)
				{
				case SDLK_ESCAPE:
					bFin = 1;
					break;

				// on deplace le sprite au clavier
				case SDLK_UP:
					fixerDirectionSprite( &spControlable, DIRECTION_HAUT );
					break;

				case SDLK_RIGHT:
					fixerDirectionSprite( &spControlable, DIRECTION_DROITE );
					break;

				case SDLK_DOWN:
					fixerDirectionSprite( &spControlable, DIRECTION_BAS );
					break;

				case SDLK_LEFT:
					fixerDirectionSprite( &spControlable, DIRECTION_GAUCHE );
					break;

				default:
					printf("Une touche à été pressée.\n");
				}
				break;

			case SDL_KEYUP:
				switch (event.key.keysym.sym)
				{
				// on deplace le sprite au clavier
				case SDLK_UP:
					if (spControlable.direction == DIRECTION_HAUT)
						fixerDirectionSprite( &spControlable, AUCUNE_DIRECTION );
					break;

				case SDLK_RIGHT:
					if (spControlable.direction == DIRECTION_DROITE)
						fixerDirectionSprite( &spControlable, AUCUNE_DIRECTION );
					break;

				case SDLK_DOWN:
					if (spControlable.direction == DIRECTION_BAS)
						fixerDirectionSprite( &spControlable, AUCUNE_DIRECTION );
					break;

				case SDLK_LEFT:
					if (spControlable.direction == DIRECTION_GAUCHE)
						fixerDirectionSprite( &spControlable, AUCUNE_DIRECTION );
					break;

				default:
					;
				}
				break;

			case SDL_QUIT:
				bFin = 1;
				break;

			default:
				;
			}
		}

		/* On recupère le temps écoulé en mili-secondes */
		temps_courant = SDL_GetTicks();

		/* On regarde s'il est temps d'effectuer le prochain rendu */
		if (temps_courant > prochain_rendu)
		{
			/* un rendu toutes les 20 milli-secondes = 50 images par secondes */
			prochain_rendu = temps_courant + 20;

			/* on met à jour le "jeu" */

			// d'abords les directions des sprites autonomes
		/*	changement_direction1--;
			if (changement_direction1 == 0)
			{
				fixerDirectionSprite( &spAutonome1 , 1 << (rand()%4) );
				changement_direction1 = rand()%100 + 50;
			}

			changement_direction2--;
			if (changement_direction2 == 0)
			{
				fixerDirectionSprite( &spAutonome2 , 1 << (rand()%4) );
				changement_direction2 = rand()%100 + 50;
			}
*/
			// puis les positions des sprites
			miseAJourSprite( &spControlable );
		//	miseAJourSprite( &spAutonome1 );
		//	miseAJourSprite( &spAutonome2 );

			/* On dessine la scene */

			/* On efface l'écran */
			SDL_FillRect(ecran, NULL, 0);

			/* On dessine les sprites à l'écran */
			dessinerSprite( &spControlable, ecran );
		//	dessinerSprite( &spAutonome1, ecran );
		//	dessinerSprite( &spAutonome2, ecran );

			/* On met à jour de la zone d'affichage de la fenetre */
			SDL_UpdateRect(ecran, 0, 0, 0, 0);
		}

	}

	//supprimerSprite( &spAutonome1 );
	//supprimerSprite( &spAutonome2 );
	supprimerSprite( &spControlable );
	SDL_Quit();
	return 0;
}
*/
