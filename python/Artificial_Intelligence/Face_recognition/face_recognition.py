# Third-Party Module
import cv2
import dlib # pypi

# BGR (blue - green - red) -> 3D

# read img                                                                  (Step 1)
img = cv2.imread('image.jpg')

# convert image to grayscale: 3D -> 2D
grayImg = cv2.cvtColor(src=img, code=cv2.COLOR_BGR2GRAY)

# dlib                                                                      (Step 2)
# Load Face Recognition Detector
face_detector = dlib.get_frontal_face_detector()

# Load the predictor
predictor = dlib.shape_predictor("shape_predictor_68_face_landmarks.dat")

# Use detector to find face landmarks
faces = face_detector(grayImg)
print(len(faces))

for face in faces:
    x1 = face.left()
    y1 = face.top()
    x2 = face.right()
    y2 = face.bottom()

    # draw a rectangles
    cv2.rectangle(img, pt1=(x1, y1), pt2=(x2, y2), color=(0, 255, 0), thickness=3)

    # predict 68 points on the face                                         (Step 3)
    face_futures = predictor(image=grayImg, box=face)
    for i in range(0, 68):
        x = face_futures.part(i).x
        y = face_futures.part(i).y

        # draw a circle
        cv2.circle(img, center=(x, y), radius=1, color=(0, 255, 0), thickness=1)
    
# show img
cv2.imshow(winname='Face Recognition App', mat=img)

# wait for a key press to exit
cv2.waitKey(delay=0)

# close window
cv2.destroyAllWindows()