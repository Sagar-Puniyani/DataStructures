import numpy as np
import matplotlib.pyplot as plt

# Creating a 3x3 grid array
grid = np.array([[255, 128, 64],
                    [32, 16, 8],
                    [4, 2, 1]], dtype=np.uint8)

# Storing grid information
gd = np.array(grid, dtype=np.uint8)

# Extracting all bit one by one
g1 = np.mod(gd, 2)
g2 = np.mod(np.floor_divide(gd, 2), 2)
g3 = np.mod(np.floor_divide(gd, 4), 2)
g4 = np.mod(np.floor_divide(gd, 8), 2)
g5 = np.mod(np.floor_divide(gd, 16), 2)
g6 = np.mod(np.floor_divide(gd, 32), 2)
g7 = np.mod(np.floor_divide(gd, 64), 2)
g8 = np.mod(np.floor_divide(gd, 128), 2)

# Combining grid again to form equivalent to original grid
gc = 2*(2*(2*(2*(2*(2*(2*g8 + g7) + g6) + g5) + g4) + g3) + g2) + g1

# Plotting bit planes
plt.figure(figsize=(10, 5))

plt.subplot(2, 5, 1)
plt.imshow(grid, cmap='gray')
plt.title('Original Grid')

for i, plane in enumerate([g1, g2, g3, g4, g5, g6, g7, g8], start=2):
    plt.subplot(2, 5, i)
    plt.imshow(plane, cmap='gray')
    plt.title(f'Bit Plane {i-1}')

# Plotting recombined grid
plt.subplot(2, 5, 10)
plt.imshow(gc, cmap='gray')
plt.title('Recombined Grid')

plt.tight_layout()
plt.show()

# Print all g1 to g8 values
print('g1:', g1)
print('g2:', g2)
print('g3:', g3)
print('g4:', g4)
print('g5:', g5)
print('g6:', g6)
print('g7:', g7)
print('g8:', g8)
