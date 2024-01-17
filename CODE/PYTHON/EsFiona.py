import pygame

pygame.init()
screen = pygame.display.set_mode((1280, 720))
clock = pygame.time.Clock()
running = True

player_pos = pygame.Vector2(screen.get_width() / 4*3, screen.get_height() / 2)
enemy_pos = pygame.Vector2(screen.get_width() / 4, screen.get_height() / 2)
projectile_pos = pygame.Vector2(enemy_pos.x, screen.get_height() / 2)

while running:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False

    screen.fill("black")
    keys = pygame.key.get_pressed()

    projectile_pos.x += 3
    if projectile_pos.x > player_pos.x:
        if not keys[pygame.K_SPACE]:
            print("You lose!")
        projectile_pos.x = enemy_pos.x

    print(projectile_pos.x)
    pygame.draw.circle(screen, "blue", projectile_pos, 10)

    # RENDER YOUR GAME HERE
    pygame.draw.circle(screen, "white", player_pos, 20)
    pygame.draw.circle(screen, "red", enemy_pos, 20)

    pygame.display.flip()

    clock.tick(60)

pygame.quit()
