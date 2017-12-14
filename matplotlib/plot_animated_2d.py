import numpy as np
import matplotlib.pyplot as plt
import matplotlib.animation as animation

figure = plt.figure()

x = np.arange(-200, 200) * .1
y = np.arange(-200, 200).reshape(-1, 1) * .1
base = np.hypot(x, y)

def imshow_func(frame, *fargs):
    return (plt.imshow(frame, norm=plt.Normalize(0, 30)),)

def pcolor_func(frame, *fargs):
    return (plt.pcolor(x, y, frame, norm=plt.Normalize(0, 30)),)

def pcolormesh_func(frame, *fargs):
    return (plt.pcolormesh(x, y, frame, norm=plt.Normalize(0, 30)),)

def gen_function_generator():
    for add in np.arange(20):
        yield base + add


# This was the only way I could think of to avoid memory leaking
_smart = []
for i in gen_function_generator():
    _smart.append((plt.imshow(i, norm=plt.Normalize(0, 30)),))
_smart_counter = 0
def smart_imshow_func(frame, *fargs):
    # (Ignores the frame)

    global _smart_counter
    data = _smart[_smart_counter]
    _smart_counter += 1
    _smart_counter = _smart_counter % len(_smart)
    return data

# Seems that 'imshow' with 'blit=True' has the best results
#
# All approaches seem to leak memory
im_ani = animation.FuncAnimation(
    figure,

    smart_imshow_func,
#     imshow_func,
#     pcolor_func,
#     pcolormesh_func,

    frames=gen_function_generator,

    interval=60,
    save_count=20,
    blit=True,
)

plt.show()
