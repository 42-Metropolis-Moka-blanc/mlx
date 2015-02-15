********************************************************************************
                                                                                
                                                          :::      ::::::::     
     Readme.txt                                         :+:      :+:    :+:     
                                                      +:+ +:+         +:+       
     By: cglavieu <cglavieu@student.42.fr>          +#+  +:+       +#+          
                                                  +#+#+#+#+#+   +#+             
     Created: 2015/02/15 07:49:55 by cglavieu          #+#    #+#               
     Updated: 2015/02/15 07:50:27 by cglavieu         ###   ########.fr         
                                                                                
********************************************************************************

ligne de compilation complete depuis le dossier "sources"

gcc -o test1 main.c hook.c draw.c coord.c libft/libft.a libmlx/libmlx.a -L/usr/X11/lib -lmlx -lXext -lX11 -I /opt/X11/include/X11
