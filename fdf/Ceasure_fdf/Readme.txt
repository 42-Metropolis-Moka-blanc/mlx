********************************************************************************
                                                                                
                                                          :::      ::::::::     
     Readme.txt                                         :+:      :+:    :+:     
                                                      +:+ +:+         +:+       
     By: cglavieu <cglavieu@student.42.fr>          +#+  +:+       +#+          
                                                  +#+#+#+#+#+   +#+             
     Created: 2015/02/15 07:49:55 by cglavieu          #+#    #+#               
     Updated: 2015/02/15 08:02:08 by cglavieu         ###   ########.fr         
                                                                                
********************************************************************************

ligne de compilation complete depuis le dossier "sources" :
	  	 - gcc -o test1 main.c hook.c draw.c coord.c libft/libft.a libmlx/libmlx.a -L/usr/X11/lib -lmlx -lXext -lX11 -I /opt/X11/include/X11

Changelogs :

		 - Gestion de carte ok
		 - Gestion affichage ok
		 - Gestion deplacement/zoom ok
		 - Gestion rotation centree ok
		 - Gestion mode image ok

Travail restant :

		 - Segfault sur map pylone
	 	 - Gestion de la couleur en fonction de z
		 - Gestion rotation sur l'axe x
		 - Implementation Z-buffer
		 - Mise a la norme
