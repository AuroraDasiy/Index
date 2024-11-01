from PIL import Image

# Load the uploaded image
input_path = 'unmute.png'
output_path_32x32 = 'unmute_icon_32x32.png'

# Open the image and resize it to 32x32
with Image.open(input_path) as img:
    img_resized = img.resize((32, 32), Image.Resampling.LANCZOS)
    img_resized.save(output_path_32x32)

output_path_32x32
