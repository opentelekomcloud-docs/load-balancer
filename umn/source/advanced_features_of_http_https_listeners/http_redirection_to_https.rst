:original_name: en-us_topic_0118840332.html

.. _en-us_topic_0118840332:

HTTP Redirection to HTTPS
=========================

Scenarios
---------

HTTPS is an extension of HTTP. HTTPS encrypts data between a web server and a browser.

If you enable redirection, all HTTP requests to your website are transmitted over HTTPS connections to improve security.

.. caution::

   -  If the listener's protocol is HTTP, only the GET or HEAD method can be used for redirection. If you create a redirect for an HTTP listener, the client browser will change POST or other methods to GET. If you want to use other methods rather than GET and HEAD, add an HTTPS listener.
   -  HTTP requests are forwarded to the HTTPS listener as HTTPS requests, which are then routed to backend servers over HTTP.
   -  If an HTTP listener is redirected to an HTTPS listener, no certificate can be deployed on the backend servers associated with the HTTPS listener. If certificates are deployed, HTTPS requests will not take effect.

Prerequisites
-------------

-  You have added an HTTPS listener.
-  You have added an HTTP listener.

Creating Redirection to HTTPS
-----------------------------

#. Log in to the management console.
#. In the upper left corner of the page, click |image1| and select the desired region and project.
#. Hover on |image2| in the upper left corner to display **Service List** and choose **Network** > **Elastic Load Balancing**.
#. Locate the load balancer and click its name.
#. Click **Listeners**, locate the HTTP listener, and click its name.
#. On the **Forwarding Policies** tab page, click **Add Forwarding Policy**.

   .. table:: **Table 1** Configuring parameters for redirection

      ========= ===========================================================
      Parameter Setting
      ========= ===========================================================
      Action    Select **Redirect to another listener**.
      Listener  Select the HTTPS listener to which requests are redirected.
      ========= ===========================================================

#. After the forwarding policy is added, click **Save**.

.. note::

   -  If requests to an HTTP listener are redirected, the listener will become invalid, but access control to the listener will still take effect.
   -  If you create a redirect for an HTTP listener, the backend server will return HTTP 301 Move Permanently to the clients.

Modifying Redirection to HTTPS
------------------------------

#. Log in to the management console.
#. In the upper left corner of the page, click |image3| and select the desired region and project.
#. Hover on |image4| in the upper left corner to display **Service List** and choose **Network** > **Elastic Load Balancing**.
#. Locate the load balancer and click its name.
#. Click **Listeners**, locate the HTTP listener, and click its name.
#. On the **Forwarding Policies** tab page, click **Edit**.
#. You can change the HTTPS listener to which requests are redirected as required.
#. Click **Save**.

Deleting Redirection to HTTPS
-----------------------------

#. Log in to the management console.
#. In the upper left corner of the page, click |image5| and select the desired region and project.
#. Hover on |image6| in the upper left corner to display **Service List** and choose **Network** > **Elastic Load Balancing**.
#. Locate the load balancer and click its name.
#. Click **Listeners**, locate the listener, and click its name.
#. On the **Forwarding Policies** tab page, click **Delete** on the right of the target forwarding policy.
#. In the **Delete Redirect** dialog box, click **Yes**.

.. |image1| image:: /_static/images/en-us_image_0000001211126503.png
.. |image2| image:: /_static/images/en-us_image_0000001417088430.png
.. |image3| image:: /_static/images/en-us_image_0000001211126503.png
.. |image4| image:: /_static/images/en-us_image_0000001417088430.png
.. |image5| image:: /_static/images/en-us_image_0000001211126503.png
.. |image6| image:: /_static/images/en-us_image_0000001417088430.png
