import numpy as np
import matplotlib.pyplot as plt
#If using termux
# import subprocess
# import shlex
#end if

x=np.array([1.0,2.0,3.0,4.0,2.0,1.0])
k = 20
f = open("values.txt","r");
content = f.read().split()
y = list(map(float, content))


#subplots
plt.subplot(2, 1, 1)
plt.stem(range(0,6),x,use_line_collection = True)
plt.title('Digital Filter Input-Output')
plt.ylabel('$x(n)$')
plt.grid()# minor


plt.subplot(2, 1, 2)
plt.stem(range(0,k),y,use_line_collection = True)
plt.xlabel('$n$')
plt.ylabel('$y(n)$')
plt.grid()# minor

#If using termux
plt.savefig('../figs/xnyn_c.pdf')
plt.savefig('../figs/xnyn_c.eps')
# subprocess.run(shlex.split("termux-open ../figs/xnyn.pdf"))
#else
#plt.show()
