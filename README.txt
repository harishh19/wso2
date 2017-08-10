
CONTENTS OF THIS FILE
---------------------

 * About Drupal
 * Configuration and features
 * Installation profiles
 * Appearance
 * Developing for Drupal
 * WSO2 Dev portal Doc

ABOUT DRUPAL
------------

Drupal is an open source content management platform supporting a variety of
websites ranging from personal weblogs to large community-driven websites. For
more information, see the Drupal website at http://drupal.org/, and join the
Drupal community at http://drupal.org/community.

Legal information about Drupal:
 * Know your rights when using Drupal:
   See LICENSE.txt in the same directory as this document.
 * Learn about the Drupal trademark and logo policy:
   http://drupal.com/trademark

CONFIGURATION AND FEATURES
--------------------------

Drupal core (what you get when you download and extract a drupal-x.y.tar.gz or
drupal-x.y.zip file from http://drupal.org/project/drupal) has what you need to
get started with your website. It includes several modules (extensions that add
functionality) for common website features, such as managing content, user
accounts, image uploading, and search. Core comes with many options that allow
site-specific configuration. In addition to the core modules, there are
thousands of contributed modules (for functionality not included with Drupal
core) available for download.

More about configuration:
 * Install, upgrade, and maintain Drupal:
   See INSTALL.txt and UPGRADE.txt in the same directory as this document.
 * Learn about how to use Drupal to create your site:
   http://drupal.org/documentation
 * Download contributed modules to sites/all/modules to extend Drupal's
   functionality:
   http://drupal.org/project/modules
 * See also: "Developing for Drupal" for writing your own modules, below.

INSTALLATION PROFILES
---------------------

Installation profiles define additional steps (such as enabling modules,
defining content types, etc.) that run after the base installation provided
by core when Drupal is first installed. There are two basic installation
profiles provided with Drupal core.

Installation profiles from the Drupal community modify the installation process
to provide a website for a specific use case, such as a CMS for media
publishers, a web-based project tracking tool, or a full-fledged CRM for
non-profit organizations raising money and accepting donations. They can be
distributed as bare installation profiles or as "distributions". Distributions
include Drupal core, the installation profile, and all other required
extensions, such as contributed and custom modules, themes, and third-party
libraries. Bare installation profiles require you to download Drupal Core and
the required extensions separately; place the downloaded profile in the
/profiles directory before you start the installation process. Note that the
contents of this directory may be overwritten during updates of Drupal core;
it is advised to keep code backups or use a version control system.

Additionally, modules and themes may be placed inside subdirectories in a
specific installation profile such as profiles/your_site_profile/modules and
profiles/your_site_profile/themes respectively to restrict their usage to only
sites that were installed with that specific profile.

More about installation profiles and distributions:
 * Read about the difference between installation profiles and distributions:
   http://drupal.org/node/1089736
 * Download contributed installation profiles and distributions:
   http://drupal.org/project/distributions
 * Develop your own installation profile or distribution:
   http://drupal.org/developing/distributions

APPEARANCE
----------

In Drupal, the appearance of your site is set by the theme (themes are
extensions that set fonts, colors, and layout). Drupal core comes with several
themes. More themes are available for download, and you can also create your own
custom theme.

More about themes:
 * Download contributed themes to sites/all/themes to modify Drupal's
   appearance:
   http://drupal.org/project/themes
 * Develop your own theme:
   http://drupal.org/documentation/theme

DEVELOPING FOR DRUPAL
---------------------

Drupal contains an extensive API that allows you to add to and modify the
functionality of your site. The API consists of "hooks", which allow modules to
react to system events and customize Drupal's behavior, and functions that
standardize common operations such as database queries and form generation. The
flexible hook architecture means that you should never need to directly modify
the files that come with Drupal core to achieve the functionality you want;
instead, functionality modifications take the form of modules.

When you need new functionality for your Drupal site, search for existing
contributed modules. If you find a module that matches except for a bug or an
additional needed feature, change the module and contribute your improvements
back to the project in the form of a "patch". Create new custom modules only
when nothing existing comes close to what you need.

More about developing:
 * Search for existing contributed modules:
   http://drupal.org/project/modules
 * Contribute a patch:
   http://drupal.org/patch/submit
 * Develop your own module:
   http://drupal.org/developing/modules
 * Follow best practices:
   http://drupal.org/best-practices
 * Refer to the API documentation:
   http://api.drupal.org/api/drupal/7

Wso2 Developer portal
----------------------

Wso2 is an open source technology provider that increases the agility of digital
businesses and enterprises engaging in digital transformation.
It offers an integrated enterprise platform Form APIs, applications, and
web services locally and across the internet. Worked with Version 2.0.0 and
store APIs.

Features involved in Dev portal integration with Wso2 :

  * APIs
  * Applications
  * User registration

APIs
----

APIs list (APIs as Entities)
----------------------------

 * APIs will be added only by provider going through wso2 instance
(https://54.172.206.43/publisher).

 * Coming to Drupal system, fetched all APIs list on cron job called
 “sealedair_wso2_store_cron” and saved as entities(apis_doc).

 * Fetch API list using Wso2 API “http://54.172.206.43/api/am/store/v0.10/apis”,
   no OAuth 2.0 scope required.

 * Generic information of API is provided using above API.
   To get details of each API with
   “http://54.172.206.43/api/am/store/v0.10/apis/{apiID}”, here also no
   OAuth 2.0 scope required.

API listing page
----------------

 * API listing page is created using views. There are two separate interfaces
   for store and publisher. So, created two different views for those instance.
   Permissions/access differs in between two roles(Consumer / Provider).
   As a provider, I will able to edit an API(just like administrator of the
   system). Where Store user can views the API listing page and API detail only
   (Read only permission).

 * API listing page contains with list of APIs in Grid view. Each Grid tile
   contains the API thumbnail, title, Edit(only for admin/provider roles),
   API description subscriptions, Action button like View full details
   (redirects to API details page), Send Trace(TODO),
   View Reports(Redirects To analytics page(TODO)) along with Tags filters.

 * Tag filters : Tags are created as term at taxonomy vocabulary called API Tag.
   These Tags are created while fetching the APIs on Cron job. Tags attribute is
   available under API details itself.

 * Subscription  : Subscription part is available on Grid tile on API listing
   page and also at API detail pages. API can subscribe to any applications.
   Fetched list of Application which are not subscribed with API viewing using
   “http://54.172.206.43/api/am/store/v0.10/subscriptions?apiID={apiId}”
   which are used as options in application drop-down.

 * Add a subscription with Application using
  “http://54.172.206.43/api/am/store/v0.10/subscriptions” with OAuth 2.0 Scope
  “apim:subscribe”(scopes are metioned separately below).

 * At subscription part, tiers are related to monetization. Those are fetched
   using “http://54.172.206.43/api/am/store/v0.10/tiers/api”.

 * Coming to API details page contains three tabs views, edit(default as drupal
   provided) and swagger(customized tab). As we know view and edit tabs are
   provided by Drupal(Out of the box). Swagger tab was added using custom
   code(hook_menu).

 * View Tab : Where user can view the details of API, as set using manage
   display of content type(apis_doc).

 * Edit Tab : Only admin/provider can do this action. As a admin/provider user,
   I will be able to edit the details of API(Drupal system only) and basically
   to add image or pdf document for displaying to an end users on
   Drupal system(Dev portal).

 * Swagger tab contains the swagger definition of the Particular API detail page
   (node page) using module called "swagger_ui_formatter". Added jquery for
   default opening the operation of APIs on page load. Where end users can use
   the available API operations. Swagger definition API
   “http://54.172.206.43/api/am/store/v0.10/apis/{apiID}/swagger”.


Applications
------------

Application listing
-------------------

 * Applications are fetched  and saved as entities(apps) on Drupal system.

 * Add a App button  redirects to application add page based on access.
   Where user can add application. Which will create an application both on wso2
   server and Drupal system. Note : Image field for thumbnail is only for Drupal
   system. Add an application using API
   “http://54.172.206.43/api/am/store/v0.10/applications”  with required
   parameter and apim:subscribe scope as metioned in OAuth 2.0 scopes topic.
   below.

Note :  Please refer to wso2 docs(url mentioned in reference part below) and
-----   this document for clear idea.
 * Application listing page contains list of applications with Grid view.
   Based on the role permission access. Application listing page Grid tile
   Contains attributes like Thumbnail, Title, Edit/delete(based on access),
   Description, Subscriptions API names.

 * Fetch the all application using API
  “http://54.172.206.43/api/am/store/v0.10/applications”  with apim:subscribe
  scopes(mentioned in OAuth 2.0 scopes part below) and no params required.

 * Subscriptions attribute : Showing the API list which subscribed to that
   particular application viewing . Retrieving APIs which are subscribed by a
   specific application. Using API
   “http://54.172.206.43/api/am/store/v0.10/subscriptions?applicationId={appId}”

 * Edit : Application edit action is based on permission access. Onclick on edit
   link, user will be able to update an application both on wso2 server and
   Drupal End. Update an application API :
   “http://54.172.206.43/api/am/store/v0.10/applications/{appId}”. With
   apim:subscribe scopes(mentioned in OAuth 2.0 scopes topic) and parameters
   as shown below :  
        {
            "callbackUrl": "",
            "throttlingTier": "Bronze",
            "description": "sample app description updated",
            "name": "sampleapp" 
   	 }

 * Delete : Application delete action is based on permission access. Onclick
   redirects to confirmation page to delete an application. Delete an app Using
   “http://54.172.206.43/api/am/store/v0.10/applications/{appID}” with
   apim:subscribe scopes(mentioned in OAuth 2.0 scopes topic) and no parameters
   required.

 * Thumbnail : Thumbnail of both Application and API details are only belongs
   Drupal entity. Not integrated with wso2 server.


User Register 
-------------
 * User registration from Developer portal(Drupal system) to Wso2 server.
   On Creating an account using default page “user/register”, using an API :
   “https://54.172.206.43/store/site/blocks/user/sign-up/ajax/user-add.jag” with
   required Url parameters like username, password, firstname and etc.. 
   
Note : Please look both Wso2 Doc and this document for easy understanding.



OAuth 2.0 Scopes
-----------------

 * All REST API was developed as a CXF REST web application running on WSO2 API
   Manager. This API comes with a pluggable security mechanism. Since API
   security is implemented as a CXF handler, if you need to plug a custom
   security mechanism, you can write your own handler and add it to the web
   service. This REST API is implemented based on REST best practices and
   specifications. API development is started with a swagger specification for
   Store and Publisher operations.

 * Before invoking the API with the access token, obtain the consumer key/secret
   key pair by calling the dynamic client registration endpoint. You can request
   an access token with the preferred grant type. To generate the authorization
   token, combine the username and password as username:password. Encode the
   combined string using base64 (http://base64encode.org). For example, if the
   username and password are admin,the encoded string would be YWRtaW46YWRtaW4=.

 * Before working with any API restricted with  OAuth2 scope, User have to
   register with WSO2 as service provider using
   “http://54.172.206.43/client-registration/v0.10/register” with required
   parameter as shown below :

    {
        "callbackUrl": "www.google.lk",
        "clientName": "rest_api_store",
        "tokenScope": "Production",
        "owner": "admin",
        "grantType": "password refresh_token",
        "saasApp": true
    }

 * During the API invocation process request, invoke the CXF handler first,
   which calls an introspection API to validate the token. Generate the access
   token using the already created OAuth application.

 * Combine the clientId and clientSecret from the response as 
   clientId:clientSecret and encode the combined string using base64 
   (http://base64encode.org) to request for the access token and the refresh
   token.

 * A sample call to generate the access token is shown below.

Note: Access token must be generated using correct scope for the resource.
      Scope for each resource is given in resource documentation.

Note: The consumer key and consumer secret keys must be Base64 encoded in the
      format consumer-key:consumer-secret, before using in the cURL command.

    curl -k -d "grant_type=password&username=admin&password=admin&
    scope=apim:subscribe" -H "Authorization: Basic 
    SGZFbDFqSlBkZzV0YnRyeGhBd3liTjA1UUdvYTpsNmMwYW9MY1dSM2Z3ZXpIaGM3WG9HT2h0NUFh"
    “https://54.172.206.43/oauth2/token” or using drupal https request providing
    the required parameter as shown above using API
    “https://54.172.206.43/oauth2/token”.

    Response sample shown below : 

    {
        "scope":"apim:subscribe",
        "token_type":"Bearer",
        "expires_in":3600,
        "refresh_token":"33c3be152ebf0030b3fb76f2c1f80bf8",
        "access_token":"292ff0fd256814536baca0926f483c8d"
    }

    From which we use access_token to fetch the required details of API with
    OAuth 2.0 scope.


Reference
---------
 * For a complete list of the currently supported Publisher APIs,
   go to https://docs.wso2.com/display/AM200/apidocs/publisher.

 * For a complete list of the currently supported store APIs,
   go to https://docs.wso2.com/display/AM200/apidocs/store.

 * OAuth 2.0 Scope : https://docs.wso2.com/display/AM200/apidocs/store/#guide



