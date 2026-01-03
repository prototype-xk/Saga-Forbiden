🎮 Saga Forbidden

Un RPG 2D solo mêlant plusieurs univers inspirés de différents jeux vidéo. Explorez des dimensions uniques, combattez des ennemis et boss, gérez votre inventaire, craftez des objets et accomplissez des quêtes dans un monde riche et immersif.

![Status](https://img.shields.io/badge/status-en%20développement-yellow)
![SQL3](https://img.shields.io/badge/SQL3-3.2.26-blue)
![C++](https://img.shields.io/badge/C++-17-00599C?logo=cplusplus)

---

## 🎯 Objectif

Sortie sur Steam prévue avant le **31 décembre 2026**.

---

## 🧩 Description du jeu

- **RPG 2D solo** avec vue top-down (ou side-scrolling, à préciser si tu veux).
- **Combats** contre des ennemis et des boss, avec gestion de points de vie, esquives et attaques.
- **Système d'inventaire**, loot, craft, équipement et commerce avec PNJ.
- **Univers** composé de plusieurs dimensions aux règles et ambiances différentes.

---

## 🗂️ Structure du projet

```text
Saga-Forbidden/
└─ Saga-Forbidden/                 # Dossier du projet Visual Studio
   ├─ external/
   │   ├─ include/                 # Headers des dépendances (SDL3, SDL3_image, SDL3_ttf)
   │   └─ lib/                     # .lib / .dll / .pdb des dépendances
   ├─ Sage-Forbidden/              # Code du jeu
   │   ├─ assets/                  # Ressources (textures, sons, polices, maps...)
   │   ├─ include/                 # Headers du jeu
   │   │   ├─ Core/                # Application, gestion SDL, etc.
   │   │   ├─ Game/                # Boucle de jeu, états, logique globale
   │   │   └─ Entities/            # Joueur, ennemis, PNJ, etc.
   │   ├─ src/                     # Implémentations C++
   │   │   ├─ Core/
   │   │   ├─ Game/
   │   │   ├─ Entities/
   │   │   └─ main.cpp             # Point d'entrée du jeu
   │   └─ x64/                     # Binaires générés par Visual Studio (Debug/Release)
   ├─ Saga-Forbidden.sln           # Solution Visual Studio
   └─ x64/                         # Autres répertoires de build (selon la config VS)
```

---

## 🛠️ Stack technique

- **Langage** : C++17
- **Framework** : SDL3 (SDL3, SDL3_image, SDL3_ttf)
- **IDE** : Visual Studio
- **Plateforme cible** : Windows (d'autres plateformes possibles plus tard)

---

## 🗺️ Roadmap Complète

### 🔴 Phase 1 : Fondations Techniques - Priorité Critique

**Configuration & Initialisation**
- [X] Installation SDL3 (version 3.2.26)
- [X] Structure de projet (src, include, assets)
- [X] Initialisation fenêtre et renderer SDL
- [X] Gestion des erreurs SDL
- [X] Résolution variable selon taille fenêtre
- [X] Fenêtre redimensionnable
- [X] Mode plein écran / fenêtré

**Boucle de Jeu**
- [ ] Boucle principale (game loop)
- [ ] Gestion du temps (delta time)
- [ ] Gestion des événements SDL
- [ ] Système de states (menu, jeu, pause)
- [ ] Transitions entre states

**Système d'Inputs**
- [ ] Détection clavier (ZQSD/WASD/Flèches)
- [ ] Détection souris (position, clics)
- [ ] Inputs continus vs ponctuels
- [ ] **Optionnel** : Support manette (SDL GameController)
- [ ] **Optionnel** : Vibration manette
- [ ] **Optionnel** : Configuration contrôles manette

**Système de Rendu**
- [ ] Rendu rectangles colorés
- [ ] Clear screen et présentation
- [ ] Layers de rendu
- [ ] Coordonnées monde vs écran
- [ ] Affichage FPS (debug)

**Personnage Prototype**
- [ ] Classe Player (rectangle)
- [ ] Position et vélocité
- [ ] Déplacement 8 directions
- [ ] Vitesse ajustable
- [ ] Rectangle de collision
- [ ] Direction du regard

**Caméra**
- [ ] Caméra 2D suivant le joueur
- [ ] Smooth camera (interpolation)
- [ ] Limites de la caméra
- [ ] Screen shake

**Tests Phase 1**
- [ ] Déplacement fluide clavier/souris
- [ ] Caméra suit correctement
- [ ] Delta time stable

---

### 🔴 Phase 2 : Systèmes de Gameplay Core - Priorité Critique

**Architecture Entités**
- [ ] Classe Entity de base
- [ ] Classes Player, Enemy, NPC
- [ ] Entity Manager
- [ ] Update() et Render()
- [ ] Identifiants uniques

**Système de Collision**
- [ ] Détection rectangle-rectangle
- [ ] Collision joueur-ennemi-murs
- [ ] Résolution collisions
- [ ] Debug hitboxes
- [ ] Optimisation (spatial grid)

**Ennemis**
- [ ] Classe Enemy (rectangle)
- [ ] Spawn dans le monde
- [ ] Mouvement et patrouille
- [ ] Détection et poursuite joueur
- [ ] Types d'ennemis variés
- [ ] Stats différentes

**Système de Combat**
- [ ] Attaque joueur
- [ ] Zone d'attaque (hitbox)
- [ ] Cooldown attaques
- [ ] Dégâts et knockback
- [ ] Attaque ennemis
- [ ] Types d'armes
- [ ] Dégâts critiques

**Système de Santé**
- [ ] HP joueur et ennemis
- [ ] Barres de vie
- [ ] I-frames après dégâts
- [ ] Animations dégâts
- [ ] Mort et drop loot
- [ ] Système armure/défense

**Game Over & Respawn**
- [ ] Écran game over
- [ ] Respawn au checkpoint
- [ ] Boutons retry/menu

**Tests Phase 2**
- [ ] Combat fluide et fonctionnel
- [ ] Collisions précises
- [ ] Mort et respawn OK

---

### 🟠 Phase 3 : Assets Graphiques & Intégration - Priorité Haute

**Sprites Joueur**
- [ ] Idle, walk, attack, hurt, death (4 directions)
- [ ] Résolution 32x32 ou 64x64
- [ ] Export PNG transparent

**Sprites Ennemis**
- [ ] 3-5 types d'ennemis
- [ ] Animations complètes par type
- [ ] Variété visuelle

**Environnements**
- [ ] Tuiles sol, murs, décors
- [ ] Tileset organisé
- [ ] Autotiling

**Chargement & Animation**
- [ ] Chargement PNG avec SDL_image
- [ ] Texture Manager
- [ ] Système d'animation (frames, durée)
- [ ] Bascule entre animations
- [ ] Sprite flipping

**Rendu**
- [ ] Remplacement rectangles par sprites
- [ ] Rendu tuiles et décors
- [ ] Z-order et culling

**Tests Phase 3**
- [ ] Visuels cohérents
- [ ] Animations fluides
- [ ] Performance OK

---

### 🟠 Phase 4 : Inventaire & Loot - Priorité Haute

**Structure Items**
- [ ] Classe Item (types, stats, rareté)
- [ ] Stackable/non-stackable
- [ ] Prix et descriptions

**Inventaire Joueur**
- [ ] Structure inventaire (slots)
- [ ] Ajout/retrait items
- [ ] Tri automatique

**Interface Inventaire**
- [ ] Fenêtre inventaire (UI)
- [ ] Grille de slots
- [ ] Icônes items
- [ ] Drag & drop
- [ ] Tooltip
- [ ] Boutons utiliser/jeter

**Système de Loot**
- [ ] Drop aléatoire ennemis
- [ ] Tables de loot
- [ ] Items au sol
- [ ] Ramassage
- [ ] Animation drop
- [ ] Notification obtention

**Équipement**
- [ ] Slots équipement (arme, armure, accessoires)
- [ ] Équiper/déséquiper
- [ ] Application stats
- [ ] Visuel change selon équipement

**Sprites Items**
- [ ] Icônes items
- [ ] Sprites au sol
- [ ] Bordures selon rareté

**Tests Phase 4**
- [ ] Inventaire fonctionnel
- [ ] Équipement change stats
- [ ] Loot équilibré

---

### 🟡 Phase 5 : Craft & Économie - Priorité Moyenne

**Système de Craft**
- [ ] Structure Recipe
- [ ] Base de données recettes
- [ ] Vérification ingrédients
- [ ] Consommation et création
- [ ] Niveaux de craft

**Interface Craft**
- [ ] Fenêtre craft (UI)
- [ ] Liste recettes
- [ ] Filtres catégories
- [ ] Aperçu résultat

**Ressources**
- [ ] Objets récoltables (arbres, rochers, plantes)
- [ ] Outils nécessaires
- [ ] Animation récolte
- [ ] Respawn ressources

**Économie**
- [ ] Système monétaire
- [ ] Porte-monnaie joueur
- [ ] Boutiques PNJ
- [ ] Interface achat/vente
- [ ] Prix dynamiques

**Tests Phase 5**
- [ ] Craft fonctionnel
- [ ] Économie équilibrée
- [ ] Récolte fluide

---

### 🟡 Phase 6 : Quêtes & PNJ - Priorité Moyenne

**Système de Dialogues**
- [ ] Fenêtre dialogue (UI)
- [ ] Texte défilant
- [ ] Portraits PNJ
- [ ] Choix multiples
- [ ] Conditions dialogues

**PNJ**
- [ ] Classe NPC
- [ ] Sprites PNJ
- [ ] Positionnement dans le monde
- [ ] Interaction joueur-PNJ
- [ ] Dialogues assignés

**Système de Quêtes**
- [ ] Structure Quest
- [ ] Types objectifs (tuer, récolter, parler)
- [ ] Progression quête
- [ ] Récompenses
- [ ] Quêtes principales et secondaires

**Journal de Quêtes**
- [ ] Interface journal (UI)
- [ ] Liste quêtes actives
- [ ] Détails quête
- [ ] Suivi objectifs
- [ ] Marqueurs sur map

**Tests Phase 6**
- [ ] Dialogues fluides
- [ ] Quêtes complétables
- [ ] Progression logique

---

### 🟡 Phase 7 : Système de Dimensions - Priorité Haute

**Génération Maps**
- [ ] Génération procédurale
- [ ] Seed pour reproductibilité
- [ ] Biomes variés
- [ ] Structures spéciales

**Portails**
- [ ] Objets portail
- [ ] Activation portail
- [ ] Téléportation entre dimensions
- [ ] Transitions visuelles
- [ ] Effet sonore

**Dimensions**
- [ ] 4+ dimensions uniques
- [ ] Ennemis spécifiques par dimension
- [ ] Ressources uniques
- [ ] Difficulté progressive
- [ ] Boss de dimension

**Sauvegarde Dimensions**
- [ ] État monde par dimension
- [ ] Ennemis tués mémorisés
- [ ] Ressources récoltées mémorisées

**Tests Phase 7**
- [ ] Téléportation fluide
- [ ] Dimensions variées
- [ ] Progression logique

---

### 🟡 Phase 8 : Boss & Combats Avancés - Priorité Moyenne

**Boss**
- [ ] Classe Boss
- [ ] Sprites et animations boss
- [ ] Salle de boss
- [ ] Patterns d'attaque
- [ ] Phases de combat
- [ ] HP élevés
- [ ] Récompenses uniques

**Combats Avancés**
- [ ] Esquive/roulade joueur
- [ ] Parade/contre-attaque
- [ ] Compétences spéciales
- [ ] Cooldowns compétences
- [ ] Mana/Énergie

**Tests Phase 8**
- [ ] Boss challengeants
- [ ] Combat varié et intéressant

---

### 🟢 Phase 9 : Audio & Ambiance - Priorité Basse

**Audio**
- [ ] Intégration SDL_mixer
- [ ] Musiques par zone/dimension
- [ ] Musiques de boss
- [ ] Effets sonores combat
- [ ] Effets sonores UI
- [ ] Effets sonores ambiance
- [ ] Contrôle volume (musique, SFX)

**Tests Phase 9**
- [ ] Audio synchronisé
- [ ] Pas de lag audio

---

### 🟠 Phase 10 : Polish & Interface - Priorité Haute

**Menus**
- [ ] Menu principal
- [ ] Boutons jouer/options/quitter
- [ ] Menu pause
- [ ] Menu options (volume, contrôles)
- [ ] Écrans de transition

**Effets Visuels**
- [ ] Particules (sang, magie, poussière)
- [ ] Feedback dégâts (nombres, flashs)
- [ ] Effets météo (pluie, neige)
- [ ] Éclairage dynamique

**Tutoriel**
- [ ] Messages tutoriels
- [ ] Première quête guidée
- [ ] Tooltips contextuels

**Optimisation**
- [ ] Profilage performance
- [ ] Optimisation rendering
- [ ] Réduction allocations mémoire
- [ ] Chargement asynchrone

**Tests Phase 10**
- [ ] Interface intuitive
- [ ] Jeu fluide
- [ ] Visuels polis

---

### 🔴 Phase 11 : Système de Sauvegarde - Priorité Critique

**Sauvegarde**
- [ ] Structure fichier sauvegarde
- [ ] Sauvegarde position joueur
- [ ] Sauvegarde inventaire
- [ ] Sauvegarde équipement
- [ ] Sauvegarde quêtes
- [ ] Sauvegarde dimensions
- [ ] Sauvegarde stats joueur
- [ ] Chiffrement sauvegarde

**Slots**
- [ ] 3+ slots de sauvegarde
- [ ] Création nouvelle partie
- [ ] Chargement partie
- [ ] Suppression sauvegarde
- [ ] Affichage infos slot (temps, niveau)

**Auto-save**
- [ ] Sauvegarde automatique périodique
- [ ] Sauvegarde lors changement dimension
- [ ] Indicateur sauvegarde

**Tests Phase 11**
- [ ] Sauvegarde fiable
- [ ] Chargement correct
- [ ] Pas de perte données

---

### 🟡 Phase 12 : Contenu & Balancing - Priorité Moyenne

**Contenu**
- [ ] 50+ items variés
- [ ] 10+ types ennemis
- [ ] 5+ boss
- [ ] 4+ dimensions complètes
- [ ] 10+ quêtes secondaires
- [ ] Lore et descriptions

**Balancing**
- [ ] Équilibrage dégâts/défense
- [ ] Équilibrage économie
- [ ] Équilibrage drop rates
- [ ] Courbe de difficulté
- [ ] Progression cohérente

**Tests Phase 12**
- [ ] Playtest complet
- [ ] Feedback joueurs
- [ ] Ajustements

---

### 🔴 Phase 13 : Intégration Steam - Priorité Critique

**Steamworks**
- [ ] Configuration Steamworks SDK
- [ ] Intégration API Steam
- [ ] Steam Cloud sauvegardes
- [ ] Overlay Steam

**Achievements**
- [ ] 20+ achievements
- [ ] Intégration dans le jeu
- [ ] Icônes achievements

**Page Steam**
- [ ] Description jeu
- [ ] Screenshots
- [ ] Trailer
- [ ] Bannières
- [ ] Tags et catégories

**Tests Phase 13**
- [ ] Build Steam fonctionnel
- [ ] Achievements débloquent
- [ ] Cloud save OK

---

### 🔴 Phase 14 : Tests Finaux - Priorité Critique

**Debugging**
- [ ] Correction bugs critiques
- [ ] Correction bugs majeurs
- [ ] Correction bugs mineurs
- [ ] Tests crashes

**Performance**
- [ ] Tests différentes configs PC
- [ ] Optimisation RAM
- [ ] Optimisation CPU/GPU
- [ ] Tests longue durée

**Playtesting**
- [ ] Tests internes complets
- [ ] Beta testeurs (si possible)
- [ ] Feedback et ajustements

---

### 🔴 Phase 15 : Release - Priorité Critique

**Préparation**
- [ ] Build finale optimisée
- [ ] Documentation Steam complète
- [ ] Trailer de lancement
- [ ] Annonces réseaux sociaux
- [ ] Prix défini

**Lancement**
- [ ] Release sur Steam
- [ ] Monitoring retours joueurs
- [ ] Support technique
- [ ] Patch Day One si nécessaire
- [ ] Collecte feedback

---

## 📊 Résumé des Priorités

### 🔴 Priorité Critique
Phase 1, 2, (13, 14, 15)

### 🟠 Priorité Haute
Phase 3, 4, 10, 11

### 🟡 Priorité Moyenne
Phase 5, 6, 7, 8, 12

### 🟢 Priorité Basse
Phase 9

---

## 🚧 Statut

**Statut actuel** : Phase 1 – Prototype technique (Janvier 2026)

---

## 👤 Auteur

**Développé par** : Prototype  
**GitHub** : [@prototype-xk](https://github.com/prototype-xk)

---

> Si tu veux, tu peux aussi ajouter plus tard une section « Installation / Build » avec : version de Visual Studio, config x64, où copier les DLL SDL, etc., quand ton projet sera un peu plus stable.
