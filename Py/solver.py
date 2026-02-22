from sympy import * 
import mpmath 
x = symbols('x')

class numericalMethod:

    @staticmethod
    def BisectionMethod(function, a, b, x0, max_iterations):
        f = sympify(function)
        iterationInfo = []
        c_prev = None
        
        for i in range(max_iterations):
            # Calculate midpoint
            c = (a + b) / 2
            
            # Calculate function values
            fa = f.subs(x, a).evalf()
            fb = f.subs(x, b).evalf()
            fc = f.subs(x, c).evalf()
            
            # Calculate relative error (skip first iteration)
            if c_prev is not None:
                rel_error = abs((c - c_prev) / c) if c != 0 else abs(c - c_prev)
            else:
                rel_error = 0
            
            # Store iteration data
            iterationInfo.append([float(a), float(b), float(c), float(fa), float(fb), float(fc), float(rel_error)])
            
            # Update interval
            if fa * fc < 0:
                b = c
            else:
                a = c
            
            c_prev = c

        return iterationInfo
    
    @staticmethod
    def FalseMethod(function, a, b, x0, max_iterations):
        f = sympify(function)
        iterationInfo = []
        c_prev = None
        
        for i in range(max_iterations):
            # Calculate function values
            fa = f.subs(x, a).evalf()
            fb = f.subs(x, b).evalf()
            
            # False position formula
            if fb - fa != 0:
                c = a - fa * (b - a) / (fb - fa)
            else:
                c = (a + b) / 2
            
            fc = f.subs(x, c).evalf()
            
            # Calculate relative error
            if c_prev is not None:
                rel_error = abs((c - c_prev) / c) if c != 0 else abs(c - c_prev)
            else:
                rel_error = 0
            
            # Store iteration data
            iterationInfo.append([float(a), float(b), float(c), float(fa), float(fb), float(fc), float(rel_error)])
            
            # Update interval
            if fa * fc < 0:
                b = c
            else:
                a = c
            
            c_prev = c

        return iterationInfo
    
    @staticmethod
    def Secant(function, a, b, x0, max_iterations):
        f = sympify(function)
        iterationInfo = []
        
        # Initialize with two points
        x_prev = a
        x_curr = b
        c_prev = None
        
        for i in range(max_iterations):
            # Calculate function values
            f_prev = f.subs(x, x_prev).evalf()
            f_curr = f.subs(x, x_curr).evalf()
            
            # Secant formula
            if f_curr - f_prev != 0:
                x_next = x_curr - f_curr * (x_curr - x_prev) / (f_curr - f_prev)
            else:
                x_next = x_curr
            
            f_next = f.subs(x, x_next).evalf()
            
            # Calculate relative error
            if c_prev is not None:
                rel_error = abs((x_next - c_prev) / x_next) if x_next != 0 else abs(x_next - c_prev)
            else:
                rel_error = 0
            
            # Store iteration data (using a,b as previous two points, c as new point)
            iterationInfo.append([float(x_prev), float(x_curr), float(x_next), float(f_prev), float(f_curr), float(f_next), float(rel_error)])
            
            # Update points
            x_prev = x_curr
            x_curr = x_next
            c_prev = x_next

        return iterationInfo
    
    @staticmethod
    def Newton(function, a, b, x0, max_iterations):
        f = sympify(function)
        f_prime = diff(f, x)
        iterationInfo = []
        c_prev = None
        
        # Start from x0
        x_curr = x0
        
        for i in range(max_iterations):
            # Calculate function values
            f_val = f.subs(x, x_curr).evalf()
            f_prime_val = f_prime.subs(x, x_curr).evalf()
            
            # Newton's method formula
            if f_prime_val != 0:
                x_next = x_curr - f_val / f_prime_val
            else:
                x_next = x_curr
            
            f_next = f.subs(x, x_next).evalf()
            
            # Calculate relative error
            if c_prev is not None:
                rel_error = abs((x_next - c_prev) / x_next) if x_next != 0 else abs(x_next - c_prev)
            else:
                rel_error = 0
            
            # Store iteration data (using a,b as dummy values, c as current approximation)
            iterationInfo.append([float(a), float(b), float(x_next), float(f_val), float(f_val), float(f_next), float(rel_error)])
            
            # Update point
            c_prev = x_curr
            x_curr = x_next

        return iterationInfo