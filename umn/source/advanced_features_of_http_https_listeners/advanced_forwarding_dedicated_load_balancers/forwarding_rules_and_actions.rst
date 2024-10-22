:original_name: elb_ug_jt_060302.html

.. _elb_ug_jt_060302:

Forwarding Rules and Actions
============================

Each HTTP or HTTPS listener has a default forwarding policy. You can also define additional forwarding policies. Each forwarding policy consists of a priority, one or more forwarding rules, and an action.

Default Forwarding Policy
-------------------------

After you add an HTTP or HTTPS listener to a load balancer, a default forwarding policy is generated. This policy uses the protocol and port specified for the listener to match requests and forward the requests to the backend server group specified when you add the listener.

The default forwarding policy has the lowest priority and is not included when you sort forwarding policies. It can be edited but cannot be deleted.

If you have enabled advanced forwarding, you can choose to disassociate the backend server group from the default forwarding policy.

.. _elb_ug_jt_060302__en-us_topic_0000001182135225_section1351817374499:

Forwarding Rule Types
---------------------

Advanced forwarding policies support the following types of forwarding rules: domain name, URL, HTTP request method, HTTP header, query string, and CIDR block (source IP addresses).

-  **Domain name**

   Route requests based on the domain name. Exact match domains and wildcard domains are supported.

   -  You can configure multiple domain names in a forwarding policy. Each domain name can contain a maximum of 100 characters.

   -  Each domain name contains at least two labels separated by dots (.). Each label can contain letters, digits, hyphens (-), periods (.), and asterisks (*), must start with a letter, digit, or asterisk (*), and cannot end with a hyphen (-). An asterisk (*) must be used as the leftmost label if you want to configure a wildcard domain name.

   -  Example

      .. code-block::

         Request URL: https://www.example.com/login.php?locale=en-us=#videos
         Domain name in the forwarding rule: www.example.com

-  **URL**

   Route requests based on URLs.

   -  You can configure multiple URLs in a forwarding policy.

   -  A URL can contain letters, digits, and special characters \_-';@^- ``%#$.*+?,=!:|\/()[]{}.`` In exact match and prefix match, the URL must start with a slash (/).

   -  There are three URL matching rules:

      -  Exact match

         The request URL is identical to the URL specified in the forwarding policy.

      -  Prefix match

         The requested URL starts with the specified URL string.

      -  Regular expression match

         The request URL matches the specified URL string based on the regular expression.

   -  Example

      .. code-block::

         Request URL: https://www.example.com/login.php?locale=en-us#videos
         URL in the forwarding rule: /login.php

   .. caution::

      If the URL contains special characters such as question marks (?) or pound keys (#), escape the special characters before configuring the forwarding rule.

-  **Query string**

   Route requests based on the query string.

   -  A query string consists of a key and one or more values. You need to set the key and values separately.

      -  The key can contain only letters, digits, and special characters ``!$'()*+,`` ``./:;=?@^-_'``
      -  Each value can contain only letters, digits, and special characters ``!$'()*+,`` ``./:;=?@^-_'.`` Asterisks (*) and question marks (?) can be used as wildcard characters.

   -  Example

      .. code-block::

         Request URL: https://www.example.com/login.php?locale=en-us#videos
         Two query strings need to be configured for the forwarding rule:
         Key: locale
         Value: en-us

-  **HTTP request method**

   Route requests based on any HTTP method.

   -  You can configure multiple request methods in a forwarding policy.
   -  The following methods are available: GET, POST, PUT, DELETE, PATCH, HEAD, and OPTIONS.

   -  Example

      .. code-block:: text

         GET

-  **HTTP header**

   Route requests based on any HTTP header.

   -  An HTTP header consists of a key and one or more values. You need to configure the key and values separately.

      -  The key can contain only letters, digits, underscores (_), and hyphens (-).
      -  Each value can contain only letters, digits, and special characters ``!#$%&'()*+,.\/:;<=>?@[]^-_'{}|~.`` Asterisks (*) and question marks (?) can be used as wildcard characters.

   -  Example

      .. code-block::

         Key: Accept-Language
         Value: en-us

-  **CIDR block (source IP addresses)**

   Route requests based on source IP addresses from where the requests originate.

   .. note::

      Both IPv4 and IPv6 addresses are supported.

   Example

   .. code-block::

      192.168.1.0/24 or 2020:50::44/127

.. _elb_ug_jt_060302__en-us_topic_0000001182135225_section107001685017:

Action Types
------------

There are four types of actions: forward to a backend server group, redirect to another listener, redirect to another URL, and return a specific response body.

-  **Forward to a backend server group**

   Requests are forwarded to the specified backend server group.

-  **Redirect to another listener**

   Requests are redirected to the specified listener, which then routes the requests to its associated backend server group.

   .. note::

      If you select **Redirect to another listener** and create a redirect for the current listener, this listener will not route requests and will redirect the requests to the specified HTTPS listener, but access control configured for the listener will still take effect.

      For example, if you configure a redirect for an HTTP listener, HTTP requests to access a web page will be redirected to the HTTPS listener you select and handled by the backend servers associated with the HTTPS listener. As a result, the clients access the web page over HTTPS.

-  **Redirect to another URL**

   Requests are redirected to the configured URL.

   When clients access website A, the load balancer returns 302 or any other 3xx status code and automatically redirects the clients to website B. You can custom the redirection URL that will be returned to the clients.

   -  Configure the following components:

      -  **Protocol**: ${protocol}, HTTP, or HTTPS. ${protocol}: retains the protocol of the request.

      -  **Domain name**: A domain name consists of at least two labels separated by periods (.). Each label can contain only letters, digits, hyphens (-), and dots (.), must start with a letter, digit, or asterisk (*), and cannot end with a hyphen (-).

         ${host}: retains the domain name of the request.

      -  **Port**: ranges from 1 to 65535. ${port}: retains the port number of the request.

      -  **Path**: A path can contain letters, digits, and special characters \_-';@^- ``%#&$.*+?,=!:|\/()[]{}`` and must start with a slash (/). **${path}**: retains the path of the request.

      -  **Query string**: A query string can contain only letters, digits, and the following special characters ``!$'()*+,`` ``./:;=?@&^-_',`` and & can only be used as a separator.

      -  **HTTP status code**: 301, 302, 303, 307, or 308

   .. note::

      Specify either the above parameters or a combination of them.

   -  Example

      .. code-block::

         URL for redirection: http://www.example1.com/index.html?locale=en-us#videos
         Protocol: HTTP
         Domain name: www.example1.com
         Port: 8081
         Path: /index.html
         Query string: locale=en-us
         HTTP status code: 301

-  **Return a specific response body**

   Load balancers return a fixed response to the clients.

   You can custom the status code and response body that load balancers directly return to the clients without the need to route the requests to backend servers.

   -  A response body consists of the following components:

      -  **HTTP status code**: By default, 2xx, 4xx, and 5xx status codes are supported.
      -  **Content-Type**: text/plain, text/css, text/html, application/javascript, or application/json
      -  **Message body**: This parameter is optional.

   -  Example

      text/plain

      .. code-block::

         Sorry, the language is not supported.

      text/css

      .. code-block::

         <head><style type="text/css">div {background-color:red}#div {font-size:15px;color:red}</style></head>

      text/html

      .. code-block::

         <form action="/" method="post" enctype="multipart/form-data"><input type="text" name="description" value="some text"><input type="file" name="myFile"><button type="submit">Submit</button></form>

      application/javascript

      .. code-block::

         String.prototype.trim = function() {var reExtraSpace = /^\s*(.*?)\s+$/;return this.replace(reExtraSpace, "$1")}

      application/json

      .. code-block::

         { "publicip": { "type": "5_bgp","ip_version": 4},"bandwidth": {"name": "bandwidth123","size": 10,"share_type": "PER"}}

      .. note::

         Ensure that the response body does not contain carriage return characters. Otherwise, it cannot be saved.
