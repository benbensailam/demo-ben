
class STUDENT:
    def __init__(self , name, major, gpa):
        self.name = name
        self.major = major
        self.gpa = gpa
    
    def getName(self):
        return self.name
    
student1 = STUDENT("Ben", "Information Technology", 3.8)
print(student1.name)