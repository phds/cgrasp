'''
Created on 23/05/2014

@author: raul
'''
from Geometry.Point import Point2D

'''Imports openCV library for Python and numpy to create the size of the window'''
import cv2
import numpy as np


class Bezier(object):
    
    def __init__(self,p):
        cv2.namedWindow('image',cv2.CV_WINDOW_AUTOSIZE)
        self.img = np.zeros((640,800,3), np.uint8)
        cv2.setMouseCallback('image', self.createPoint, 0)
        self.control_points=np.array([],int).reshape(0,2)
        self.points=[]
        self.pointsCurve=np.array([],int).reshape(0,2)
        self.p=p
    def main(self):
        while True:      
            cv2.imshow('image',self.img)
            k=cv2.waitKey(0)
            if k==27: #esc
                break
            elif k==100: # 'd'
                self.drawControlPoints(self.control_points)
                while len(self.points)>1:
                    self.drawLines(self.points)
               
                
                self.pointsCurve=np.vstack([self.pointsCurve,[self.points[0].X,self.points[0].Y]])
                self.pointsCurve=np.vstack([self.pointsCurve,[self.control_points[-1][0],self.control_points[-1][1]]])
                
                '''
                #cv2.polylines(self.img,np.int32([self.pointsCurve]),0,(255,255,0))
                Tentativa frustada de fazer uma curva
                for i in range(1,len(self.pointsCurve)):
                    cv2.line(self.img,(int(self.pointsCurve[i-1][0]),int(self.pointsCurve[i-1][1])),(int(self.pointsCurve[i][0]),int(self.pointsCurve[i][1])),(255,255,0),1)
                '''
        cv2.destroyWindow("image")
        
    
    def drawControlPoints(self,control_points):
        #desenha as linhas dos pontos de controle
        
        self.pointsCurve=np.vstack([self.pointsCurve,[self.control_points[0][0],self.control_points[0][1]]])
        for i in range(1,len(self.control_points)):
            cv2.line(self.img,(int(self.control_points[i-1][0]),int(self.control_points[i-1][1])),(int(self.control_points[i][0]),int(self.control_points[i][1])),(255,255,255),1)
        
    def drawLines(self,points):
        l=len(self.points)
        #desenha um ponto da interpolacao
        for i in range(1,len(self.points)):
            p=self.points[i-1].linear_interpolation(self.points[i],self.p)
            self.points.append(p)
        
        self.points=self.points[l:]
        #desenha as linhas das interpolacoes    
        for i in range(1,len(self.points)):
            cv2.line(self.img,(int(self.points[i-1].X),int(self.points[i-1].Y)),(int(self.points[i].X),int(self.points[i].Y)),(255,255,255),1)
        
        
            
    def createPoint(self,event,x,y,flag=0,param=None):
        if event==cv2.EVENT_LBUTTONDBLCLK:
            p = Point2D(x,y)
            self.control_points=np.vstack([self.control_points,[p.X,p.Y]])
            self.points.append(p)
            #desenha um ponto
            cv2.line(self.img,(p.X,p.Y),(p.X,p.Y),(255,0,0),3)
            cv2.imshow('image',self.img)
           
            
        
                
        
            
            
            
        
        


if __name__=="__main__":
    b=Bezier(0.5)
    b.main()
