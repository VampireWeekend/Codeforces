# -*- coding: utf-8 -*-
"""
Created on Sun Mar 18 15:55:16 2018

@author: VampireWeekend
"""

import Queue
q=Queue.Queue()

q.put(2)
q.put(3)
l,r=(int(x) for x in raw_input().split())
ceil=2e9
a=[1,2,3]
while not q.empty():
    now=q.get()
#    print a
    if now*2<=ceil and a.count(now*2)==0:
        q.put(now*2)
        a.append(now*2)
    if now*3<=ceil and a.count(now*3)==0:
        q.put(now*3)
        a.append(now*3)
ans=0
for i in a:
    if i>=l and i<=r:
        ans+=1

print ans