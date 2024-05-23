class Car:
    total_cars = 0
    def __init__(self ,brand , model ) :
        self.__brand = brand
        self.__model = model
        Car.total_cars += 1

    def getFullname(self):
        print(f"{self.__model} - {self.__brand}")
    
    def get_brand(self):
        print(f"{self.__brand}")
    
    @staticmethod
    def general_description():
        print("Cars are Means of transport")

    @property
    def model(self):
        print(f"{self.__model}")


class ElectricCar(Car):
    def __init__(self ,brand , model , batterysize):
        super().__init__(brand , model)
        self.batterysize = batterysize




# mycar = Car("Toyota" , "xyz")
# print(mycar)
# print(mycar.model)
# print(mycar.brand)
# mycar.getFullname()

my_tesla = ElectricCar("Tesla" , "Model S" , "85kWH")
# print(my_tesla)
# # print(my_tesla.brand)
# my_tesla.getFullname()
# my_tesla.get_brand()
# print(Car.total_cars)
my_tesla.general_description()

# my_tesla.model = "City"
my_tesla.model

print(isinstance(my_tesla , Car))
print(isinstance(my_tesla , ElectricCar))





