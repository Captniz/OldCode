
import math
from PIL import Image

"""
All images you work with will be formatted as a 
dictionary with keys: "height", "width", and "pixels".
Use the helper functions below to show the image/save the image.
"""

def correlate(image, kernel, boundary_behavior="extend"):
    """
    Compute the result of correlating the given image with the given kernel.
    `boundary_behavior` will one of the strings "zero", "extend", or "wrap",
    and this function will treat out-of-bounds pixels as having the value zero,
    the value of the nearest edge, or the value wrapped around the other edge
    of the image, respectively.

    if boundary_behavior is not one of "zero", "extend", or "wrap", return
    None.

    Otherwise, the output of this function should have the same form as an
    image (a dictionary with "height", "width", and "pixels" keys), but its
    pixel values do not necessarily need to be in the range [0,255], nor do
    they need to be integers (they should not be clipped or rounded at all).

    This process should not mutate the input image; rather, it should create a
    separate structure to represent the output.

    KERNAL IS: a string of numbers separated by a space.
    """
    # Convert kernel string to a list of floats
    kernel = [float(x) for x in kernel.split()]

    # Check if boundary_behavior is valid
    if boundary_behavior not in ["zero", "extend", "wrap"]:
        return None

    # Create a new image to store the result
    n_image = {
        "height": image["height"],
        "width": image["width"],
        "pixels": []
    }

    # Iterate over each pixel in the image
    for i in range(image["height"]):
        for j in range(image["width"]):
            # Apply the kernel to the pixel and its neighbors
            result = 0.0
            for m in range(len(kernel)):
                for n in range(len(kernel)):
                    # Calculate the coordinates of the neighbor pixel
                    row = i + m - len(kernel) // 2
                    col = j + n - len(kernel) // 2

                    # Handle out-of-bounds pixels based on boundary_behavior
                    if boundary_behavior == "zero":
                        if row < 0 or col < 0 or row >= image["height"] or col >= image["width"]:
                            neighbor_pixel = 0
                        else:
                            neighbor_pixel = image["pixels"][image["width"] * row + col]
                    elif boundary_behavior == "extend":
                        row = max(0, min(row, image["height"] - 1))
                        col = max(0, min(col, image["width"] - 1))
                        neighbor_pixel = image["pixels"][image["width"] * row + col]
                    elif boundary_behavior == "wrap":
                        row = (row + image["height"]) % image["height"]
                        col = (col + image["width"]) % image["width"]
                        neighbor_pixel = image["pixels"][image["width"] * row + col]

                    # Multiply the neighbor pixel by the corresponding kernel value
                    result += neighbor_pixel * kernel[m * len(kernel) + n]

            # Add the result to the new image
            n_image["pixels"].append(result)

    return n_image

def get_pixel(image, row, col, edgetype="zero"):
    """
    Takes in image dict, row, col, edgetype (with default 'zero')
    Returns the color of the pixel at that location
    """
    if edgetype == "zero":
        if row < 0 or col < 0 or row >= image["height"] or col >= image["width"]:
            return 0
        return image["pixels"][image["width"]*row + col]
    elif edgetype == "extend":
        if row < 0:
            row = 0
        if col < 0:
            col = 0
        if row >= image["height"]:
            row = image["height"]-1
        if col >= image["width"]:
            col = image["width"]-1
        return image["pixels"][image["width"]*row + col]
    elif edgetype == "wrap":
        if row < 0:
            row = image["height"]-1
        if col < 0:
            col = image["width"]-1
        if row >= image["height"]:
            row = 0
        if col >= image["width"]:
            col = 0
        return image["pixels"][image["width"]*row + col]

def set_pixel(image, row, col, color,edgetype="zero"):
    """
    OPTIONAL helper function that takes in an image,
    row, column, and a new color.
    Changes the color at that location
    """
    if edgetype == "zero":
        if row < 0 or col < 0 or row >= image["height"] or col >= image["width"]:
            return 0
        image["pixels"][image["width"]*row + col] = color
    elif edgetype == "extend":
        if row < 0:
            row = 0
        if col < 0:
            col = 0
        if row >= image["height"]:
            row = image["height"]-1
        if col >= image["width"]:
            col = image["width"]-1
            image["pixels"][image["width"]*row + col] = color
    elif edgetype == "wrap":
        if row < 0:
            row = image["height"]-1
        if col < 0:
            col = image["width"]-1
        if row >= image["height"]:
            row = 0
        if col >= image["width"]:
            col = 0
        image["pixels"][image["width"]*row + col] = color
    return 0

def apply_per_pixel(image, func):
    """
    OPTIONAL helper function that takes in an image 
    and applies a function to every pixel in the image.
    Returns the altered image
    """
    for i in image["pixels"]:
        func(i)
    return 0

def inverted(image):
    """
    Returns an image that has been inverted
    """
    n_image = image.copy()
    n_image["pixels"] = []
    for i in range(0,image["height"]):
        for j in range(0,image["width"]):
            n_image["pixels"].append(get_pixel(image, i, image["width"]-j-1, edgetype="extend"))
    print(n_image["height"]," ", n_image["width"])
    return n_image

def round_and_clip(color):
    """
    Rounds/clips a pixel color - color must be an integer or a tuple of integers and be between [0, 255]
    Returns the color(s) it should be
    """
    if isinstance(color, float) or isinstance(color, int):
        if color > 255:
            return 255
        elif color < 0:
            return 0
        else:
            return int(round(color))
    elif isinstance(color, tuple):
        return tuple(round_and_clip(c) for c in color)
    else:
        raise ValueError("Invalid color format")  

def round_and_clip_image(image):
    """
    Given a dictionary, ensure that the values in the "pixels" list are all
    integers in the range [0, 255].

    All values should be converted to integers using Python's `round` function.

    Any locations with values higher than 255 in the input should have value
    255 in the output; and any locations with values lower than 0 in the input
    should have value 0 in the output.
    """

    n_image = image.copy()
    n_image["pixels"] = []
    for i in image["pixels"]:
        n_image["pixels"].append(round_and_clip(i))
    return n_image

def boxblurrer(n):
    """
    Takes in n, returns nxn square of identical values that sum to 1
    Returns a kernal (string seperated by whitespace)
    n will always be odd.
    Example: boxblurrer(3) should return 
    "0.111111 0.1111111 0.1111111 0.1111111 0.1111111 0.1111111 0.1111111 0.1111111 0.1111111"
    """
    k = ""
    for _ in range(n*n):
        k += str(1/(n*n)) + " "
    return k

def blurred(image, kernel_size, boundary="extend"):
    """
    Return a new image representing the result of applying a box blur (with the
    given kernel size) to the given input image.

    This process should not mutate the input image; rather, it should create a
    separate structure to represent the output.
    """
def blurred(image, kernel_size, boundary="extend"):
    """
    Return a new image representing the result of applying a box blur (with the
    given kernel size) to the given input image.

    This process should not mutate the input image; rather, it should create a
    separate structure to represent the output.
    """
    kernel = boxblurrer(kernel_size)  # Get the box blur kernel
    blurred_image = correlate(image, kernel, boundary)  # Apply the kernel using the correlate function
    return blurred_image


def sharpened(image, n):
    """
    Takes in an image and a kernel size
    Returns a new image with each pixel being (2*original pixel)- blurred pixel
    """
    pass


def edges(image):
    """
    Takes in an image
    Applies 2 different kernels to each pixel, and combines into new pixel value
    Returns a funky image with strange white edges!
    """
    # defining given kernels
    k1 = "-1 -2 -1 0  0  0 1  2  1"
    k2 = "-1 0 1 -2 0 2 -1 0 1"
    # two new dicts with applied kernels
    o1_dict = correlate(image, k1, "extend")
    o2_dict = correlate(image, k2, "extend")
    orc_list = []  # new pixel list
    # for each pixel, combining their values
    for o1, o2 in zip(o1_dict["pixels"], o2_dict["pixels"]):
        orc = round(math.sqrt((o1**2) + (o2**2)))
        orc_list.append(orc)
    # returning new edges dict
    edges_dict = {
        "height": image["height"],
        "width": image["width"],
        "pixels": orc_list,
    }
    return round_and_clip_image(edges_dict)


# VARIOUS FILTERS
def split_color_image(color_image):
    """
    Takes in a color image, with each pixel as (red, green, blue)
    Returns a list of [red image, green image, blue image]
    """
    pass


def combine_color_image(list_of_rgb):
    """
    Takes in list of dictionaries [red image, green image, blue image]
    Returns one dictionary of a color image with tuple pixels
    """
    pass


def color_filter_from_greyscale_filter(filt):
    """
    Given a filter that takes a greyscale image as input and produces a
    greyscale image as output, returns a function that takes a color image as
    input and produces the filtered color image.
    You should apply the filter to each entry in (red, green, blue)
    """
    #defines function that applies to color image
    pass


def make_blur_filter(kernel_size):
    """
    Makes a blur filter (a function) with the kernel size
    """
    pass


def make_sharpen_filter(kernel_size):
    """
    Returns a sharpen filter (a function) with the kernel size
    """
    #making a new function takes in image
    pass


def filter_cascade(filters):
    """
    Given a list of filters (implemented as functions on images), returns a new
    single filter such that applying that filter to an image produces the same
    output as applying each of the individual ones in turn.
    """
    pass


# SEAM CARVING

# Main Seam Carving Implementation
round_and_clip_color_image = color_filter_from_greyscale_filter(round_and_clip_image) #used in seam carving


def seam_carving(image, ncols):
    """
    Starting from the given image, use the seam carving technique to remove
    ncols (an integer) columns from the image. Returns a new image.
    """
    #copying image to alter it
    new_image = image.copy()
    new_image["pixels"] = image["pixels"][:]
    #applying helper functions below, each time removing 1 seam
    for _ in range(ncols):
        grey = greyscale_image_from_color_image(new_image) #grey dict
        cem = cumulative_energy_map(compute_energy(grey))
        new_image = image_without_seam(new_image, minimum_energy_seam(cem))
    return round_and_clip_color_image(new_image)


# Optional Helper Functions for Seam Carving


def greyscale_image_from_color_image(image):
    """
    Given a color image, computes and returns a corresponding greyscale image.

    Returns a greyscale image (represented as a dictionary).
    """
    grey_val = [] #new list of grey pixels
    [red, green, blue] = split_color_image(image)
    for r, g, b in zip(red["pixels"], green["pixels"], blue["pixels"]): #iterating over pixels in each color dict
        grey_val.append(round(0.299 * int(r) + 0.587 * int(g) + 0.114 * int(b)))
    grey_dict = {"height": image["height"], "width": image["width"], "pixels": grey_val}
    return grey_dict


def compute_energy(grey):
    """
    Given a greyscale image, computes a measure of "energy", in our case using
    the edges function from last week.

    Returns a greyscale image (represented as a dictionary).
    """
    return edges(grey)


def cumulative_energy_map(energy):
    """
    Given a measure of energy (e.g., the output of the compute_energy
    function), computes a "cumulative energy map".

    Returns a dictionary with 'height', 'width', and 'pixels' keys (but where
    the values in the 'pixels' array may not necessarily be in the range [0,
    255], you will round/clip later.
    """
    pass


def minimum_energy_seam(cem):
    """
    Given a cumulative energy map, returns a list of the indices into the
    'pixels' list that correspond to pixels contained in the minimum-energy
    seam.
    """
    # first find the minimum of the bottom row, which will be the starting pixel.

    # next find the location of the minimum above. It should be adjacent to the pixel (left, center, or right)
    pass


def image_without_seam(image, seam):
    """
    Given a grey image and a list of indices to be removed from the image,
    return a new image (without modifying the original) that contains all the
    pixels from the original image except those corresponding to the locations
    in the given list.
    """
    #{"height": height, "width": width, "pixels": pixels}
    n_image = image.copy()
    for p in seam:
        n_image["pixels"][p] = (0,0,0) #.pop(p) #! Cosa succede se non li rimpiazzo?
    return n_image


def correlate_color(image, k):
    '''
    Takes in a color image
    Applies correlate to 3 seperate color dictionaries, returning a color correlate
    '''
    #TODO!
    pass


def custom_feature(image):
    """
    Takes in an image. Choose a filter to apply!
    """
    pass

########################################################
# HELPER FUNCTIONS FOR LOADING AND SAVING COLOR IMAGES #
########################################################

def load_color_image(filename):
    """
    Loads a color image from the given file and returns a dictionary
    representing that image.

    Invoked as, for example:
       i = load_color_image('test_images/cat.png')
    """
    with open(filename, "rb") as img_handle:
        img = Image.open(img_handle)
        img = img.convert("RGB")  # in case we were given a greyscale image
        img_data = img.getdata()
        pixels = list(img_data)
        width, height = img.size
        return {"height": height, "width": width, "pixels": pixels}


def save_color_image(image, filename, mode="PNG"):
    """
    Saves the given color image to disk or to a file-like object.  If filename
    is given as a string, the file type will be inferred from the given name.
    If filename is given as a file-like object, the file type will be
    determined by the 'mode' parameter.
    """
    out = Image.new(mode="RGB", size=(image["width"], image["height"]))
    out.putdata(image["pixels"])
    if isinstance(filename, str):
        out.save(filename)
    else:
        out.save(filename, mode)
    out.close()


def load_greyscale_image(filename):
    """
    Loads an image from the given file and returns an instance of this class
    representing that image.  This also performs conversion to greyscale.

    Invoked as, for example:
       i = load_greyscale_image('test_images/cat.png')
    """
    with open(filename, "rb") as img_handle:
        img = Image.open(img_handle)
        img_data = img.getdata()
        if img.mode.startswith("RGB"):
            pixels = [
                round(0.299 * p[0] + 0.587 * p[1] + 0.114 * p[2]) for p in img_data
            ]
        elif img.mode == "LA":
            pixels = [p[0] for p in img_data]
        elif img.mode == "L":
            pixels = list(img_data)
        else:
            raise ValueError(f"Unsupported image mode: {img.mode}")
        width, height = img.size
        return {"height": height, "width": width, "pixels": pixels}


def save_greyscale_image(image, filename, mode="PNG"):
    """
    Saves the given image to disk or to a file-like object.  If filename is
    given as a string, the file type will be inferred from the given name.  If
    filename is given as a file-like object, the file type will be determined
    by the 'mode' parameter.
    """
    out = Image.new(mode="L", size=(image["width"], image["height"]))
    out.putdata(image["pixels"])
    if isinstance(filename, str):
        out.save(filename)
    else:
        out.save(filename, mode)
    out.close()


if __name__ == "__main__":
    img = load_color_image("9.png")
    save_color_image(blurred(img,3), "9_s.png")
