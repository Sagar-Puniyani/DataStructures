import time

# type 1: timmer
def timer(function):
    def wrapper(*args , **kwargs):
        start = time.time()
        result = function(*args , **kwargs)
        end = time.time()
        print(f"{function.__name__} ran in {end-start} second")
        return result
    return wrapper 

@timer
def example_function(n):
    time.sleep(n)

example_function(1)

#  Type 2: debug
def debug(func):
    def wrapper(*args , **kwargs):
        args_value = ", ".join(str(arg) for arg in args)
        kwargs_value = ", ".join(f"{k}={v}" for k,v in kwargs.items())
        print(f"calling by {func.__name__}")
        print(f"arguments  is {args_value}")
        print(f"key value arguments  is {kwargs_value}")

        return func(*args , **kwargs)
    return wrapper


@debug
def greet(name , greeting="Hello"):
    print(f"{greeting}, {name}")

greet("sagar", greeting="Hi")


# type 3: cache
def cache(func):
    cache_value = {}
    print(cache_value)
    def wrapper(*args , **kwargs):
        if args in cache_value:
            return cache_value[args]
        result =  func(*args , **kwargs)
        cache_value[args] = result
        return result
    return wrapper

@cache 
@timer
def long_running_function(a, b):
    time.sleep(3)
    return a*b

print(long_running_function(2,3))
print(long_running_function(2,3))
print(long_running_function(2,5))
print(long_running_function(2,5))