</p>
<p align="center">
<img src="https://github.com/Elhazin/PNG/blob/main/Screen%20Shot%202023-04-30%20at%207.34.48%20PM.png" width="250">

<p/>

##  So_long

This project is a part of 42projects. It involves creating a simple 2D game where the player needs to collect items and exit to end the game. The objective of the game is to control the player's movement and make the player collect all the required items before exiting.
## Ressource

 - [All what you will need](https://harm-smits.github.io/42docs/libs/minilibx)
 - [use this website to chnage you png to xpm file](https://convertio.co/xpm-png/)
 - [use this website to resize your image](https://www.iloveimg.com/resize-image/resize-png)



## Running program

To run the program, you need to link it with the minilibx library. To do this, add the following command to your makefile:
```bash
  -l mlx -framework OpenGL -framework Appkit
```



## Usage/Examples
Let us start with some basic stuff :
```c

int main(void)
{
	void *mlx_ptr;
	void *win_ptr;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "mlx 42");
	mlx_loop(mlx_ptr);
}
```
- void * mlx_init(void);

    ~ This funcion connects your the mlx_function and it returns a structure containing all the useful stuff 
- void * mlx_new_window ( void mlx_ptr, int size_x, int size_y, char *title );
    
    ~ This function opens a new window on the display. Receives the previously obtained pointer, width and height size, and title of the window and displays them.
- int mlx_loop ( void *mlx_ptr );

    ~This function waits for events such as keyboard and mouse input and then handles them appropriately.
##
</p>
<p align="center">
<img src="https://github.com/Elhazin/So_long/blob/master/get_next_line/so_long.png" width="1500">
<p/>

#

Now let us know how to handle events : 
```c
int event(int keycode)
{
    printf("This the number of the key that you have press : %d\n", keycode);
    return (0);
}
int main(void)
{
	void *mlx_ptr;
	void *win_ptr;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "Minilibx");
  mlx_hook(win, X_EVENT_KEY_RELEASE, 0, &event, NULL);
	mlx_loop(mlx_ptr);
}
```
* int mlx_hook(void *win_ptr, int x_event, int x_mask, int (*func)(), void *param);

    ~ This function is going to call the event(int keycode); Whenever a key is pressed while the window is in focus
  #
Now let us see how to get image and put them in the window 
```c
int event(int keycode)
{
    printf("This the number of the key that you have press : %d\n", keycode);
    return (0);
}
int main(void)
{
    void *mlx_ptr;
    void *win_ptr;
    void *img;
    int img_width, img_height;

    mlx_ptr = mlx_init();

    win_ptr = mlx_new_window(mlx_ptr, 500, 500, "Minilibx");
  
    img = mlx_xpm_file_to_image(mlx, ".image/xpm", &img_width, &img_height);
  
    mlx_put_image_to_window(mlx, win, img, 0, 0);
  
    mlx_hook(win, X_EVENT_KEY_RELEASE, 0, &event, NULL);
	
    mlx_loop(mlx_ptr);
}
```

- void * mlx_xpm_file_to_image(void *mlx_ptr, char *filename, int *width, int *height)

    ~ This function gets the mlx pointer, file address, and horizontal and vertical size, upload them to memory, and return the address of the memory.
- int mlx_put_image_to_window(void *mlx_ptr, void *win_ptr, void *img_ptr, int x, int y);

    ~ Receives an image, receives pointers to be displayed as arguments, and designates coordinates in the window to display in the relevant window

