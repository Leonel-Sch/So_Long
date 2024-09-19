#!/bin/bash

# Nom de votre exécutable
EXECUTABLE="./so_long"

# Dossier contenant les fichiers de cartes
MAPS_DIR="./maps"

# Couleurs pour les messages
GREEN='\033[0;32m'
RED='\033[0;31m'
NC='\033[0m' # No Color

# Vérifiez si l'exécutable existe
if [ ! -f "$EXECUTABLE" ]; then
    echo -e "${RED}L'exécutable $EXECUTABLE n'existe pas.${NC}"
    exit 1
fi

# Vérifiez si le dossier de cartes existe
if [ ! -d "$MAPS_DIR" ]; then
    echo -e "${RED}Le dossier $MAPS_DIR n'existe pas.${NC}"
    exit 1
fi

# Fonction pour tronquer le nom de la carte
truncate_map_name() {
    local map_name="$1"
    local max_length=20
    if [ ${#map_name} -gt $max_length ]; then
        echo "${map_name:0:$max_length}..."
    else
        echo "$map_name"
    fi
}

# Itérer sur chaque fichier de carte dans le dossier
for map in "$MAPS_DIR"/*; do
    truncated_map=$(truncate_map_name "$(basename "$map")")
    $EXECUTABLE "$map" > /dev/null 2>&1
    if [ $? -eq 0 ]; then
        echo -e "${truncated_map}: ${GREEN}OK${NC}"
    else
        echo -e "${truncated_map}: ${RED}KO${NC}"
    fi
done