import pygame

#spile resolution
r=1

x1=0
y1=0

#2nd WayPoint

x2=0
y2=7

#3rd WayPoint

x3=7
y3=7


# spline_optimizer

xi_1=(x2-x1)/(2**r)
yi_1=(y2-y1)/(2**r)

xi_2=(x3-x2)/(2**r)
yi_2=(y3-y2)/(2**r)


pygame.init()


window = pygame.display.set_mode(300, 300)
colour = (0,200,0)

pygame.draw.line(screen, blue, [x1,y1],[xi_1,yi_1],4)
pygame.draw.line(screen, blue, [xi_1,yi_1],[x2,y2],4)
pygame.draw.line(screen, blue, [x2,y2],[xi_2,yi_2],4)
pygame.draw.line(screen, blue, [xi_2,yi_2],[x3,y3],4)
pygame.draw.line(screen, red, [x1,y1],[x2,y2],2)
pygame.draw.line(screen, red, [x2,y2],[x3,y3],2)
