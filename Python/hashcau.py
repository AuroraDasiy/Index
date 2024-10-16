import hashlib

def get_file_hash(file_path, algorithm='sha256'):
    hash_func = hashlib.new(algorithm)
    with open(file_path, 'rb') as f:
        for chunk in iter(lambda: f.read(4096), b""):
            hash_func.update(chunk)
    return hash_func.hexdigest()

# 示例用法
file_path = 'python.md'
print(get_file_hash(file_path, 'md5'))

#14993656f3c4180ed50d4ccdea474230