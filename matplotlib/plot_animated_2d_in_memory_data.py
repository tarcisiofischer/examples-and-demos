import numpy as np
import matplotlib.pyplot as plt
import matplotlib.animation as animation

'''
This approach doesn't seem to leak memory, but it seem slower than the one
in the plot_animated_2d module...
'''

N_FRAMES = 40
x = np.arange(-200, 200) * .2
y = np.arange(-200, 200).reshape(-1, 1) * .2
base = np.hypot(x, y)

f = plt.figure()
ax = f.gca()
plot = ax.pcolormesh(x, y, base, cmap='plasma')

frames = [(base + i)[:-1, :-1].flatten() for i in range(N_FRAMES)]
def animate(i):
    plot.set_array(frames[i])

anim = animation.FuncAnimation(f, animate, frames=N_FRAMES, interval=60)

plt.draw()
plt.show()
