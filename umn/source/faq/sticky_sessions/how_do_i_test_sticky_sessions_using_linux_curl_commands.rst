:original_name: elb_faq_0067.html

.. _elb_faq_0067:

How Do I Test Sticky Sessions Using Linux Curl Commands?
========================================================

#. Prepare required resources.

   a. Buy three ECSs, one as the client and the other two as backend servers.
   b. Create a load balancer and add an HTTP listener to the load balancer. Enable sticky sessions when you add the listener.

2. Start the HTTP service of the two backend servers.

   Log in to a backend server and create a file named **1.file** in the current directory to mark this server.

   Run the following command in the current directory to start the HTTP service:

   **nohup python -m SimpleHTTPServer 80 &**

   Run the following command to check whether the HTTP service is normal:

   **curl http://127.0.0.1:80**

   |image1|

   Log in to the other backend server and create a file named **2.file** in the current directory.

   Run the following command in the current directory to start the HTTP service:

   **nohup python -m SimpleHTTPServer 80 &**

   Run the following command to check whether the HTTP service is normal:

   **curl http://127.0.0.1:80**

   |image2|

3. Access the load balancer from the client and specify the cookie value.

   The following is an example command. Change the parameters as needed. Ensure that the returned file names of each request are the same.

   **curl --cookie "name=abcd" http://ELB_IP:Port**

   |image3|

.. |image1| image:: /_static/images/en-us_image_0000001747739620.jpg
.. |image2| image:: /_static/images/en-us_image_0000001747380744.jpg
.. |image3| image:: /_static/images/en-us_image_0000001794819569.jpg
