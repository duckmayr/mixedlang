        integer function facto(n)
c
c Simple subroutine to compute factorial
c Example taken from 
c https://www.r-bloggers.com/2014/04/fortran-and-r-speed-things-up/
c
        integer n, answer, i

        answer = 1
        do 100 i = 2,n
           answer = answer * i
  100   continue 
  
        facto = answer
        
        end function facto